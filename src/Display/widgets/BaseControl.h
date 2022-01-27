#pragma once
#include <Display/misc/StyleHandle.h>
#include <map>
#include <Display/function_maker.hpp>

class CAnimation;
class CBaseControl
{
public:
    void create(lv_obj_t* pParent);
    virtual void create(std::shared_ptr<CBaseControl> pParent);
    virtual void create(std::shared_ptr<CBaseControl>, std::shared_ptr<CBaseControl> pPtr);
    void setParent(std::shared_ptr<CBaseControl> pParent);
    void addStyle(std::shared_ptr<CStyle> style, lv_style_selector_t selector);
    void setStyleTextFont(const lv_font_t *font, lv_style_selector_t selector);
    void setStyleBaseDir(lv_base_dir_t value, lv_style_selector_t selector);
    void setStyleSize(lv_coord_t value, lv_style_selector_t selector);

    CAnimation* addAnimation(const std::string& srAnimName);
    CAnimation* getAnimation(const std::string& srAnimName);

    template<class _lambdaexpr>
    void addEventCallback(_lambdaexpr&& lexpr, lv_event_code_t filter)
    {
        m_events.emplace(filter, std::forward<_lambdaexpr>(lexpr));
        lv_obj_add_event_cb(m_pInstance.get(), &CBaseControl::event, filter, this);
    }

    template<class _Class, class _ReturnType, class... Args>
    void addEventCallback(_Class *c, _ReturnType (_Class::*m)(Args...), lv_event_code_t filter)
    {
        m_events.emplace(filter, std::move(make_func(c, m)));
        lv_obj_add_event_cb(m_pInstance.get(), &CBaseControl::event, filter, this);
    }

    void setPosition(lv_coord_t x, lv_coord_t y);
    void setSize(lv_coord_t w, lv_coord_t h);
    void setWidth(lv_coord_t w);
    void setHeight(lv_coord_t h);
    void setAlign(lv_align_t align, lv_coord_t x_ofs = 0, lv_coord_t y_ofs = 0);
    void setAlignTo(const lv_obj_t* obj, lv_align_t align, lv_coord_t x_ofs = 0, lv_coord_t y_ofs = 0);
    void clearFlag(lv_obj_flag_t f);
    void removeStyle(CStyle* style, lv_style_selector_t selector = 0);

    lv_obj_t* getObj();
private:
    static void event(lv_event_t* e);
    void handleEvents(lv_event_t* e);
    std::map<lv_event_code_t, std::function<void(lv_event_t* e)>> m_events;
    std::map<std::string, CAnimation*> m_animations;
protected:
    std::unique_ptr<lv_obj_t> m_pInstance;
};