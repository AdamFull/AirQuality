#pragma once
#include <map>
#include <string>
#include <memory>
#include <SPI.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "Display/lvgl.hpp"

static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

class DisplayHandler
{
public:
    void Create();
    void Update();

    template<class T>
    T* AddControl(const std::string& ctrl_name)
    {
        auto ptr = new T();
        m_ctrls.emplace(ctrl_name, ptr);
        return ptr;
    }

    template<class T>
    T* GetControl(const std::string& ctrl_name)
    {
        return static_cast<T*>(m_ctrls[ctrl_name]);
    }

    CStyleHandle* AddStyle(const std::string& style_name);
    CStyleHandle* GetStyle(const std::string& style_name);

    static void Flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
private:
    static std::unique_ptr<TFT_eSPI> display;
    std::map<std::string, CBaseControl*> m_ctrls;
    std::map<std::string, CStyleHandle*> m_styles;

    unsigned long current_time{0}, old_time{0};
    lv_disp_draw_buf_t draw_buf;
    lv_color_t buf[ screenWidth * 10 ];
};
