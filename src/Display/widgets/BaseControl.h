#pragma once
#include <Display/misc/StyleHandle.h>
#include <map>
#include <Display/EasyDelegate.hpp>

class CAnimation;
class CBaseControl
{
public:
    void create(lv_obj_t* pParent);
    virtual void create(std::shared_ptr<CBaseControl> pParent);
    virtual void create(std::shared_ptr<CBaseControl>, std::shared_ptr<CBaseControl> pPtr);
    void setParent(std::shared_ptr<CBaseControl> pParent);
    void addStyle(std::shared_ptr<CStyle> style, lv_style_selector_t selector);
    void refreshStyle(lv_part_t part, lv_style_prop_t prop);
    void removeStyle(std::shared_ptr<CStyle> style, lv_style_selector_t selector);
    void setStyleTextFont(const lv_font_t *font, lv_style_selector_t selector);
    void setStyleBaseDir(lv_base_dir_t value, lv_style_selector_t selector);
    void setStyleSize(lv_coord_t value, lv_style_selector_t selector);
    void setStyleLocalLineColor(lv_style_prop_t prop, lv_style_value_t value, lv_style_selector_t selector);

    CAnimation* addAnimation(const std::string& srAnimName);
    CAnimation* getAnimation(const std::string& srAnimName);

    template<class... Args>
    void addEventCallback(Args... args, lv_event_code_t filter)
    {
        m_events.emplace(filter, std::move(EasyDelegate::TDelegate<void(lv_event_t* e)>(std::forward<Args>(args)...)));
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
    std::map<lv_event_code_t, EasyDelegate::TDelegate<void(lv_event_t* e)>> m_events;
    std::map<std::string, CAnimation*> m_animations;
protected:
    std::unique_ptr<lv_obj_t> m_pInstance;
};