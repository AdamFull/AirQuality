#include "Switch.h"

void CSwitch::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_switch_create(pParent->getObj()));
    CBaseControl::create(pParent);
}