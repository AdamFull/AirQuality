#include "Colorwheel.h"

CColorwheel::CColorwheel(bool knob_recolor) :
    m_bKnobRecolor(knob_recolor)
{

}

void CColorwheel::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_colorwheel_create(pParent->getObj(), true));
    CBaseControl::create(pParent);
}

bool CColorwheel::setHsv(lv_color_hsv_t hsv)
{
    return lv_colorwheel_set_hsv(m_pInstance.get(), hsv);
}

bool CColorwheel::setRgb(lv_color_t color)
{
    return lv_colorwheel_set_rgb(m_pInstance.get(), color);
}

void CColorwheel::setMode(lv_colorwheel_mode_t mode)
{
    lv_colorwheel_set_mode(m_pInstance.get(), mode);
}

void CColorwheel::setModeFixed(bool fixed)
{
    lv_colorwheel_set_mode_fixed(m_pInstance.get(), fixed);
}

lv_color_hsv_t CColorwheel::getHsv()
{
    return lv_colorwheel_get_hsv(m_pInstance.get());
}

lv_color_t CColorwheel::getRgb()
{
    return lv_colorwheel_get_rgb(m_pInstance.get());
}

lv_colorwheel_mode_t CColorwheel::getColorMode()
{
    return lv_colorwheel_get_color_mode(m_pInstance.get());
}

bool CColorwheel::getColorModeFixed()
{
    return lv_colorwheel_get_color_mode_fixed(m_pInstance.get());
}
