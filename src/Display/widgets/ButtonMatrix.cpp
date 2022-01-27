#include "ButtonMatrix.h"

void CButtonMatrix::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_btnmatrix_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CButtonMatrix::setMap(const char * map[])
{
    lv_btnmatrix_set_map(m_pInstance.get(), map);
}

void CButtonMatrix::setCtrlMap(const lv_btnmatrix_ctrl_t ctrl_map[])
{
    lv_btnmatrix_set_ctrl_map(m_pInstance.get(), ctrl_map);
}

void CButtonMatrix::setSelectedButton(uint16_t btn_id)
{
    lv_btnmatrix_set_selected_btn(m_pInstance.get(), btn_id);
}

void CButtonMatrix::setButtonCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl)
{
    lv_btnmatrix_set_btn_ctrl(m_pInstance.get(), btn_id, ctrl);
}

void CButtonMatrix::clearButtonCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl)
{
    lv_btnmatrix_clear_btn_ctrl(m_pInstance.get(), btn_id, ctrl);
}

void CButtonMatrix::setButtonCtrlAll(lv_btnmatrix_ctrl_t ctrl)
{
    lv_btnmatrix_set_btn_ctrl_all(m_pInstance.get(), ctrl);
}

void CButtonMatrix::clearButtonCtrlAll(lv_btnmatrix_ctrl_t ctrl)
{
    lv_btnmatrix_clear_btn_ctrl_all(m_pInstance.get(), ctrl);
}

void CButtonMatrix::setButtonWidth(uint16_t btn_id, uint8_t width)
{
    lv_btnmatrix_set_btn_width(m_pInstance.get(), btn_id, width);
}

void CButtonMatrix::setOneChecked(bool en)
{
    lv_btnmatrix_set_one_checked(m_pInstance.get(), en);
}

const char** CButtonMatrix::getMap()
{
    return lv_btnmatrix_get_map(m_pInstance.get());
}

uint16_t CButtonMatrix::getSelectedButton()
{
    return lv_btnmatrix_get_selected_btn(m_pInstance.get());
}

const char* CButtonMatrix::getButtonText(uint16_t btn_id)
{
    return lv_btnmatrix_get_btn_text(m_pInstance.get(), btn_id);
}

bool CButtonMatrix::hasButtonCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl)
{
    return lv_btnmatrix_has_btn_ctrl(m_pInstance.get(), btn_id, ctrl);
}

bool CButtonMatrix::getOneChecked()
{
    return lv_btnmatrix_get_one_checked(m_pInstance.get());
}
