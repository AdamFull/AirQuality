
#include "List.h"

void CList::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_list_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

CLabel* CList::addText(const std::string& srName, const std::string& srText)
{
    auto newLabel = new CLabel();
    m_pControls.emplace(srName, newLabel);
    //newLabel->create(m_pInstance->parent, lv_list_add_text(m_pInstance.get(), srText.c_str()));
    return newLabel;
}

CButton* CList::addButton(const std::string& srName, const char * icon, const std::string& srText)
{
    auto newButton = new CButton();
    m_pControls.emplace(srName, newButton);
    //newButton->create(m_pInstance->parent, lv_list_add_btn(m_pInstance.get(), icon, srText.c_str()));
    return newButton;
}

const char* CList::getButtonText(const std::string& srName)
{
    return lv_list_get_btn_text(m_pInstance.get(), m_pControls[srName]->getObj());
}