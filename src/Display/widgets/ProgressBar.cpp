#include "ProgressBar.h"

void CProgressBar::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_bar_create(pParent));
    CBaseControl::create(pParent);
}

void CProgressBar::setValue(int32_t value, lv_anim_enable_t anim)
{
    lv_bar_set_value(m_pInstance.get(), value, anim);
}

void CProgressBar::setStartValue(int32_t value, lv_anim_enable_t anim)
{
    lv_bar_set_start_value(m_pInstance.get(), value, anim);
}

void CProgressBar::setRange(int32_t min, int32_t max)
{
    lv_bar_set_range(m_pInstance.get(), min, max);
}

void CProgressBar::setMode(lv_bar_mode_t mode)
{
    lv_bar_set_mode(m_pInstance.get(), mode);
}

int32_t CProgressBar::getValue()
{
    return lv_bar_get_value(m_pInstance.get());
}

int32_t CProgressBar::getStartValue()
{
    return lv_bar_get_start_value(m_pInstance.get());
}

int32_t CProgressBar::getMinValue()
{
    return lv_bar_get_min_value(m_pInstance.get());
}

int32_t CProgressBar::getMaxValue()
{
    return lv_bar_get_max_value(m_pInstance.get());
}

lv_bar_mode_t CProgressBar::getMode()
{
    return lv_bar_get_mode(m_pInstance.get());
}
    