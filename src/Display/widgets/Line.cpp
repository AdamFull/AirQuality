#include "Line.h"

void CLine::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_line_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CLine::addPoint(int16_t x, int16_t y)
{
    vPoints.emplace_back(lv_point_t{x, y});
}

void CLine::removePoint(uint32_t pos)
{
    vPoints.erase(std::next(vPoints.begin(), pos));
}

void CLine::clear()
{
    vPoints.clear();
    update();
}

void CLine::update()
{
    lv_line_set_points(m_pInstance.get(), vPoints.data(), vPoints.size());
}

void CLine::setInvertY(bool en)
{
    lv_line_set_y_invert(m_pInstance.get(), en);
}

bool CLine::isInvertY()
{
    return lv_line_get_y_invert(m_pInstance.get());
}