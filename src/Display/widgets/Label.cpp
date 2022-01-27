#include "Label.h"

void CLabel::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_label_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CLabel::create(std::shared_ptr<CBaseControl> pParent, std::shared_ptr<CBaseControl> pPtr)
{
    m_pInstance.reset(pPtr->getObj());
    CBaseControl::create(pParent, pPtr);
}

void CLabel::setText(const std::string& srText)
{
    lv_label_set_text(m_pInstance.get(), srText.c_str());
}

void CLabel::setLondMode(const lv_label_long_mode_t& mode)
{
    lv_label_set_long_mode(m_pInstance.get(), mode);
}

void CLabel::setRecolor(bool bValue)
{
    lv_label_set_recolor(m_pInstance.get(), bValue);
}

void CLabel::setTextSelStart(uint32_t index)
{
    lv_label_set_text_sel_start(m_pInstance.get(), index);
}

void CLabel::setTextSelEnd(uint32_t index)
{
    lv_label_set_text_sel_end(m_pInstance.get(), index);
}

std::string CLabel::getText()
{
    return std::string(lv_label_get_text(m_pInstance.get()));
}

lv_label_long_mode_t CLabel::getLongMode()
{
    return lv_label_get_long_mode(m_pInstance.get());
}

bool CLabel::getRecolor()
{
    return lv_label_get_recolor(m_pInstance.get());
}

lv_point_t CLabel::getLetterPos(uint32_t id)
{
    lv_point_t point;
    lv_label_get_letter_pos(m_pInstance.get(), id, &point);
    return point;
}

uint32_t CLabel::getLetterOn(lv_point_t* pos)
{
    return lv_label_get_letter_on(m_pInstance.get(), pos);
}

bool CLabel::isCharUnderPos(lv_point_t* pos)
{
    return lv_label_is_char_under_pos(m_pInstance.get(), pos);
}

uint32_t CLabel::getTextSelectionStart()
{
    return lv_label_get_text_selection_start(m_pInstance.get());
}

uint32_t CLabel::getTextSelectionEnd()
{
    return lv_label_get_text_selection_end(m_pInstance.get());
}

void CLabel::insert(const std::string& srText, uint32_t pos)
{
    lv_label_ins_text(m_pInstance.get(), pos, srText.c_str());
}

void CLabel::cut(uint32_t pos, uint32_t count)
{
    lv_label_cut_text(m_pInstance.get(), pos, count);
}