#include "SpinBox.h"

void CSpinbox::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_spinbox_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CSpinbox::setValue(int32_t i)
{
    lv_spinbox_set_value(m_pInstance.get(), i);
}

void CSpinbox::setRollover(bool b)
{
    lv_spinbox_set_rollover(m_pInstance.get(), b);
}

void CSpinbox::setDigitFormat(uint8_t digit_count, uint8_t separator_position)
{
    lv_spinbox_set_digit_format(m_pInstance.get(), digit_count, separator_position);
}

void CSpinbox::setStep(uint32_t step)
{
    lv_spinbox_set_step(m_pInstance.get(), step);
}

void CSpinbox::setRange(int32_t range_min, int32_t range_max)
{
    lv_spinbox_set_range(m_pInstance.get(), range_min, range_max);
}

void CSpinbox::setPos(uint8_t pos)
{
    lv_spinbox_set_pos(m_pInstance.get(), pos);
}

void CSpinbox::setDigitStepDirection(lv_dir_t direction)
{
    lv_spinbox_set_digit_step_direction(m_pInstance.get(), direction);
}

int32_t CSpinbox::getValue()
{
    return lv_spinbox_get_value(m_pInstance.get());
}

int32_t CSpinbox::getStep()
{
    return lv_spinbox_get_step(m_pInstance.get());
}

void CSpinbox::stepNext()
{
    lv_spinbox_step_next(m_pInstance.get());
}

void CSpinbox::stepPrev()
{
    lv_spinbox_step_prev(m_pInstance.get());
}

bool CSpinbox::getRollover()
{
    return lv_spinbox_get_rollover(m_pInstance.get());
}   

void CSpinbox::increment()
{
    lv_spinbox_increment(m_pInstance.get());
}

void CSpinbox::decrement()
{
    lv_spinbox_decrement(m_pInstance.get());
}
