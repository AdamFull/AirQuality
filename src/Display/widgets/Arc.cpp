#include "Arc.h"

void CArc::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_arc_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CArc::setStartAngle(uint16_t start)
{
    lv_arc_set_start_angle(m_pInstance.get(), start);
}

void CArc::setEndAngle(uint16_t end)
{
    lv_arc_set_end_angle(m_pInstance.get(), end);
}

void CArc::setAngles(uint16_t start, uint16_t end)
{
    lv_arc_set_angles(m_pInstance.get(), start, end);
}

void CArc::setBgStartAngle(uint16_t start)
{
    lv_arc_set_bg_start_angle(m_pInstance.get(), start);
}

void CArc::setBgEndAngle(uint16_t end)
{
    lv_arc_set_bg_end_angle(m_pInstance.get(), end);
}

void CArc::setBgAngles(uint16_t start, uint16_t end)
{
    lv_arc_set_bg_angles(m_pInstance.get(), start, end);
}

void CArc::setRotation(uint16_t rotation)
{
    lv_arc_set_rotation(m_pInstance.get(), rotation);
}

void CArc::setMode(lv_arc_mode_t type)
{
    lv_arc_set_mode(m_pInstance.get(), type);
}

void CArc::setValue(int16_t value)
{
    lv_arc_set_value(m_pInstance.get(), value);
}

void CArc::setRange(int16_t min, int16_t max)
{
    m_valueMin = min;
    m_valueMax = max;
    lv_arc_set_range(m_pInstance.get(), min, max);
}

void CArc::setChangeRate(uint16_t rate)
{
    lv_arc_set_change_rate(m_pInstance.get(), rate);
}

uint16_t CArc::getAngleStart()
{
    return lv_arc_get_angle_start(m_pInstance.get());
}

uint16_t CArc::getAngleEnd()
{
    return lv_arc_get_angle_end(m_pInstance.get());
}

uint16_t CArc::getBgAngleStart()
{
    return lv_arc_get_bg_angle_start(m_pInstance.get());
}

uint16_t CArc::getBgAngleEnd()
{
    return lv_arc_get_bg_angle_end(m_pInstance.get());
}

int16_t CArc::getValue()
{
    return lv_arc_get_value(m_pInstance.get());
}

int16_t CArc::getMinValue()
{
    return lv_arc_get_min_value(m_pInstance.get());
}

int16_t CArc::getMaxValue()
{
    return lv_arc_get_max_value(m_pInstance.get());
}

lv_arc_mode_t CArc::getMode()
{
    return lv_arc_get_mode(m_pInstance.get());
}