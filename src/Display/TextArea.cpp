#include "TextArea.h"

void CTextArea::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_textarea_create(pParent));
    CBaseControl::create(pParent);
}

void CTextArea::addChar(uint32_t c)
{
    lv_textarea_add_char(m_pInstance.get(), c);
}

void CTextArea::addText(const std::string& srText)
{
    lv_textarea_add_text(m_pInstance.get(), srText.c_str());
}

void CTextArea::delChar()
{
    lv_textarea_del_char(m_pInstance.get());
}

void CTextArea::delCharForward()
{
    lv_textarea_del_char_forward(m_pInstance.get());
}

void CTextArea::setText(const std::string& srText)
{
    lv_textarea_set_text(m_pInstance.get(), srText.c_str());
}

void CTextArea::setTextPlaceholder(const std::string& srText)
{
    lv_textarea_set_placeholder_text(m_pInstance.get(), srText.c_str());
}

void CTextArea::setCorsorPos(int32_t pos)
{
    lv_textarea_set_cursor_pos(m_pInstance.get(), pos);
}

void CTextArea::setCursorClickPos(bool en)
{
    lv_textarea_set_cursor_click_pos(m_pInstance.get(), en);
}

void CTextArea::setPasswordMode(bool en)
{
    lv_textarea_set_password_mode(m_pInstance.get(), en);
}

void CTextArea::setOneLine(bool en)
{
    lv_textarea_set_one_line(m_pInstance.get(), en);
}

void CTextArea::setAcceptedChars(const std::string& srText)
{
    lv_textarea_set_accepted_chars(m_pInstance.get(), srText.c_str());
}

void CTextArea::setMaxLength(uint32_t num)
{
    lv_textarea_set_max_length(m_pInstance.get(), num);
}

void CTextArea::setInsertReplace(const std::string& srText)
{
    lv_textarea_set_insert_replace(m_pInstance.get(), srText.c_str());
}

void CTextArea::setTextSelection(bool en)
{
    lv_textarea_set_text_selection(m_pInstance.get(), en);
}

void CTextArea::setPasswordShowTime(uint16_t time)
{
    lv_textarea_set_password_show_time(m_pInstance.get(), time);
}

void CTextArea::setTextAlign(lv_text_align_t align)
{
    lv_textarea_set_align(m_pInstance.get(), align);
}

std::string CTextArea::getText()
{
    return std::string(lv_textarea_get_text(m_pInstance.get()));
}

std::string CTextArea::getPlaceholderText()
{
    return std::string(lv_textarea_get_placeholder_text(m_pInstance.get()));
}

lv_obj_t* CTextArea::getLabel()
{
    return lv_textarea_get_label(m_pInstance.get());
}

uint32_t CTextArea::getCursorPos()
{
    return lv_textarea_get_cursor_pos(m_pInstance.get());
}

bool CTextArea::getCursorClickPos()
{
    return lv_textarea_get_cursor_click_pos(m_pInstance.get());
}

bool CTextArea::getPasswordMode()
{
    return lv_textarea_get_password_mode(m_pInstance.get());
}

bool CTextArea::getOneLine()
{
    return lv_textarea_get_one_line(m_pInstance.get());
}

std::string CTextArea::getAcceptedChars()
{
    return std::string(lv_textarea_get_accepted_chars(m_pInstance.get()));
}

uint32_t CTextArea::getMaxLength()
{
    return lv_textarea_get_max_length(m_pInstance.get());
}

bool CTextArea::isSelected()
{
    return lv_textarea_text_is_selected(m_pInstance.get());
}

bool CTextArea::getTextSelected()
{
    return lv_textarea_get_text_selection(m_pInstance.get());
}

uint16_t CTextArea::getTextShowTime()
{
    return lv_textarea_get_password_show_time(m_pInstance.get());
}

void CTextArea::clearSelection()
{
    lv_textarea_clear_selection(m_pInstance.get());
}

void CTextArea::cursorRight()
{
    lv_textarea_cursor_right(m_pInstance.get());
}

void CTextArea::cursorLeft()
{
    lv_textarea_cursor_left(m_pInstance.get());
}

void CTextArea::cursorDown()
{
    lv_textarea_cursor_down(m_pInstance.get());
}

void CTextArea::cursorUp()
{
    lv_textarea_cursor_up(m_pInstance.get());
}