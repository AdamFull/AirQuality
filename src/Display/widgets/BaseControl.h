#pragma once
#include "../misc/StyleHandle.h"

class CBaseControl
{
public:
    virtual void create(lv_obj_t* pParent);
    void setParent(lv_obj_t* pParent);
    void addStyle(CStyleHandle* style, lv_style_selector_t selector);
    void setStyleTextFont(const lv_font_t *font, lv_style_selector_t selector);
    void setStyleBaseDir(lv_base_dir_t value, lv_style_selector_t selector);
    void setStyleSize(lv_coord_t value, lv_style_selector_t selector);

    void setPosition(lv_coord_t x, lv_coord_t y);
    void setSize(lv_coord_t w, lv_coord_t h);
    void setWidth(lv_coord_t w);
    void setHeight(lv_coord_t h);
    void setAlign(lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);
    void setAlignTo(const lv_obj_t* obj, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);
    void clearFlag(lv_obj_flag_t f);
    void removeStyle(CStyleHandle* style, lv_style_selector_t selector);

    lv_obj_t* getObj();
protected:
    std::unique_ptr<lv_obj_t> m_pInstance;
};