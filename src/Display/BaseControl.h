#pragma once
#include <lvgl.h>
#include <memory>

class CBaseControl
{
public:
    virtual void create(lv_obj_t* pParent) { }
    void setParent(lv_obj_t* pParent);
    void addStyle(lv_style_t* style, lv_style_selector_t selector);
    void setStyleTextFont(const lv_font_t *font, lv_style_selector_t selector);

    void setPosition(lv_coord_t x, lv_coord_t y);
    void setSize(lv_coord_t w, lv_coord_t h);
    void setWidth(lv_coord_t w);
    void setHeight(lv_coord_t h);
    void setAlign(lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);
    void setAlignTo(const lv_obj_t* obj, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);

    lv_obj_t* getObj();
protected:
    std::unique_ptr<lv_obj_t> m_pInstance;
};