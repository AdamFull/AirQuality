#pragma once
#include <map>
#include <string>
#include <memory>
#include <SPI.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <Display/lvgl.hpp>

static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

class DisplayHandler
{
public:
    void Create();
    void Update();

    /*template<class _lambdaexpr>
    void setOnCreateCallback(_lambdaexpr&& lexpr)
    {
        m_pOnCreateCallback = std::forward<_lambdaexpr>(lexpr);
    }*/

    template<class _Class, class _ReturnType, class... Args>
    void setOnCreateCallback(_Class *c, _ReturnType (_Class::*m)(Args...))
    {
        m_pOnCreateCallback = std::move(make_func(c, m));
    }

    template<class T>
    std::shared_ptr<T> AddControl(const std::string& ctrl_name, std::shared_ptr<CBaseControl> pParent)
    {
        auto ptr = std::make_shared<T>();
        ptr->create(pParent);
        m_ctrls.emplace(ctrl_name, ptr);
        return ptr;
    }

    template<class T>
    std::shared_ptr<T> AddControl(const std::string& ctrl_name, lv_obj_t* pParent)
    {
        auto ptr = std::make_shared<T>();
        ptr->create(pParent);
        m_ctrls.emplace(ctrl_name, ptr);
        return ptr;
    }

    template<class T>
    std::shared_ptr<T> GetControl(const std::string& ctrl_name)
    {
        return std::dynamic_pointer_cast<T>(m_ctrls[ctrl_name]);
    }

    std::shared_ptr<CStyle> AddStyle(const std::string& style_name);
    std::shared_ptr<CStyle> GetStyle(const std::string& style_name);

    static void Flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
private:
    static std::unique_ptr<TFT_eSPI> display;
    std::map<std::string, std::shared_ptr<CBaseControl>> m_ctrls;
    std::map<std::string, std::shared_ptr<CStyle>> m_styles;
    std::function<void(std::shared_ptr<CBaseControl>)> m_pOnCreateCallback;

    unsigned long current_time{0}, old_time{0};
    lv_disp_draw_buf_t draw_buf;
    lv_color_t buf[ screenWidth * 10 ];
};
