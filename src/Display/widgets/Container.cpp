#include "Container.h"

void CContainer::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_obj_create(pParent->getObj()));
    CBaseControl::create(pParent);
}