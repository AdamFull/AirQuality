#include "CheckBox.h"

void CCheckBox::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_checkbox_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CCheckBox::setText(const std::string& srText)
{
    lv_checkbox_set_text(m_pInstance.get(), srText.c_str());
}

void CCheckBox::setTextStatic(const std::string& srText)
{
    lv_checkbox_set_text_static(m_pInstance.get(), srText.c_str());
}

std::string CCheckBox::getText()
{
    return std::string(lv_checkbox_get_text(m_pInstance.get()));
}