#include "Menu.h"

void CMenu::create(std::shared_ptr<CBaseControl> pParent)
{
    //m_pInstance.reset(lv_menu_create(pParent->getObj()));
    CBaseControl::create(pParent);
}