#include "Switch.h"

void CSwitch::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_switch_create(pParent));
    CBaseControl::create(pParent);
}