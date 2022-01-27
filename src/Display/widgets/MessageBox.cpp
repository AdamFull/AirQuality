#include "MessageBox.h"

CMessageBox::CMessageBox(const std::string& title, const std::string& text, const std::vector<const char*>& btn_txts, bool add_close_btn) :
    m_srTitle(title), m_srText(text), m_vButtonTexts(btn_txts), m_bAddCloseBtn(add_close_btn)
{

}

void CMessageBox::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_msgbox_create(pParent->getObj(), m_srTitle.c_str(), m_srText.c_str(), m_vButtonTexts.data(), m_bAddCloseBtn));
    CBaseControl::create(pParent);
}

std::unique_ptr<CBaseControl> CMessageBox::getTitle()
{
    auto pTitle = std::make_unique<CBaseControl>();
    pTitle->create(lv_msgbox_get_title(m_pInstance.get()));
    return pTitle;
}

std::unique_ptr<CBaseControl> CMessageBox::getCloseButton()
{
    auto pButton = std::make_unique<CBaseControl>();
    pButton->create(lv_msgbox_get_close_btn(m_pInstance.get()));
    return pButton;
    
}

std::unique_ptr<CBaseControl> CMessageBox::getText()
{
    auto pText = std::make_unique<CBaseControl>();
    pText->create(lv_msgbox_get_text(m_pInstance.get()));
    return pText;
}

std::unique_ptr<CBaseControl> CMessageBox::getContent()
{
    auto pContent = std::make_unique<CBaseControl>();
    pContent->create(lv_msgbox_get_content(m_pInstance.get()));
    return pContent;
    
}

std::unique_ptr<CBaseControl> CMessageBox::getButtons()
{
    auto pButtons = std::make_unique<CBaseControl>();
    pButtons->create(lv_msgbox_get_btns(m_pInstance.get()));
    return pButtons;
}

uint16_t CMessageBox::getActiveButton()
{
    return lv_msgbox_get_active_btn(m_pInstance.get());
}

std::string CMessageBox::getActiveButtonText()
{
    return std::string(lv_msgbox_get_active_btn_text(m_pInstance.get()));
}

void CMessageBox::close()
{
    lv_msgbox_close(m_pInstance.get());
}

void CMessageBox::closeAsync()
{
    lv_msgbox_close_async(m_pInstance.get());
}
