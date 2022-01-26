#include "Slider.h"

void CSlider::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_slider_create(pParent));
    CBaseControl::create(pParent);
}

bool CSlider::isDragged()
{
    return lv_slider_is_dragged(m_pInstance.get());
}   
