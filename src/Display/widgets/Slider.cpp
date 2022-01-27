#include "Slider.h"

void CSlider::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_slider_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

bool CSlider::isDragged()
{
    return lv_slider_is_dragged(m_pInstance.get());
}   
