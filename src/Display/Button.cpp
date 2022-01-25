#include "Button.h"

void CButton::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_btn_create(pParent));
    CBaseControl::create(pParent);
}