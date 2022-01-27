#include "Button.h"

void CButton::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_btn_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CButton::create(std::shared_ptr<CBaseControl> pParent, std::shared_ptr<CBaseControl> pPtr)
{
    m_pInstance.reset(pPtr->getObj());
    CBaseControl::create(pParent, pPtr);
}