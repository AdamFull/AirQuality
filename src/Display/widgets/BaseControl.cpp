#include "BaseControl.h"

void CBaseControl::create(lv_obj_t* pParent)
{
    if(!m_pInstance)
    {
        m_pInstance.reset(pParent);
    }
}

void CBaseControl::setParent(lv_obj_t* pParent)
{
    lv_obj_set_parent(m_pInstance.get(), pParent);
}

void CBaseControl::addStyle(CStyleHandle* style, lv_style_selector_t selector) 
{ 
    if(style)
    {
        lv_obj_add_style(m_pInstance.get(), style->get(), selector);
    }
}

void CBaseControl::setStyleTextFont(const lv_font_t *font, lv_style_selector_t selector)
{
    lv_obj_set_style_text_font(m_pInstance.get(), font, selector);
}

void CBaseControl::setStyleBaseDir(lv_base_dir_t value, lv_style_selector_t selector)
{
    lv_obj_set_style_base_dir(m_pInstance.get(), value, selector);
}

void CBaseControl::setStyleSize(lv_coord_t value, lv_style_selector_t selector)
{
    lv_obj_set_style_size(m_pInstance.get(), value, selector);
}

void CBaseControl::setPosition(lv_coord_t x, lv_coord_t y)
{
    lv_obj_set_pos(m_pInstance.get(), x, y);
}

void CBaseControl::setSize(lv_coord_t w, lv_coord_t h)
{
    lv_obj_set_size(m_pInstance.get(), w, h);
}

void CBaseControl::setWidth(lv_coord_t w)
{
    lv_obj_set_width(m_pInstance.get(), w);
}

void CBaseControl::setHeight(lv_coord_t h)
{
    lv_obj_set_height(m_pInstance.get(), h);
}

void CBaseControl::setAlign(lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_obj_align(m_pInstance.get(), align, x_ofs, y_ofs);
}

void CBaseControl::setAlignTo(const lv_obj_t* obj, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_obj_align_to(m_pInstance.get(), obj, align, x_ofs, y_ofs);
}

lv_obj_t* CBaseControl::getObj()
{
    return m_pInstance.get();
}

void CBaseControl::clearFlag(lv_obj_flag_t f)
{
    lv_obj_clear_flag(m_pInstance.get(), f);
}

void CBaseControl::removeStyle(CStyleHandle* style, lv_style_selector_t selector)
{
    lv_obj_remove_style(m_pInstance.get(), style ? style->get() : nullptr, selector);
}