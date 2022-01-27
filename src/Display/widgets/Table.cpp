#include "Table.h"

void CTable::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_table_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CTable::setCellValue(uint16_t row, uint16_t col, const std::string& srText)
{
    lv_table_set_cell_value(m_pInstance.get(), row, col, srText.c_str());
}

void setCellValueFormat()
{
    //lv_table_set_cell_value_fmt(m_pInstance.get(), );
}

void CTable::setRowCount(uint16_t row_cnt)
{
    lv_table_set_row_cnt(m_pInstance.get(), row_cnt);
}

void CTable::setColCount(uint16_t col_cnt)
{
    lv_table_set_col_cnt(m_pInstance.get(), col_cnt);
}

void CTable::setColWidth(uint16_t col_id, lv_coord_t w)
{
    lv_table_set_col_width(m_pInstance.get(), col_id, w);
}

void CTable::addCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl)
{
    lv_table_add_cell_ctrl(m_pInstance.get(), row, col, ctrl);
}

void CTable::clearCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl)
{
    lv_table_clear_cell_ctrl(m_pInstance.get(), row, col, ctrl);
}

std::string CTable::getCellValue(uint16_t row, uint16_t col)
{
    return std::string(lv_table_get_cell_value(m_pInstance.get(), row, col));
}

uint16_t CTable::getRowCount()
{
    return lv_table_get_row_cnt(m_pInstance.get());
}

uint16_t CTable::getColCount()
{
    return lv_table_get_col_cnt(m_pInstance.get());
}

lv_coord_t CTable::getColWidth(uint16_t col)
{
    return lv_table_get_col_width(m_pInstance.get(), col);
}

bool CTable::hasCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl)
{
    return lv_table_has_cell_ctrl(m_pInstance.get(), row, col, ctrl);
}

std::pair<uint16_t, uint16_t> CTable::getSelectedCell()
{
    uint16_t row, col;
    lv_table_get_selected_cell(m_pInstance.get(), &row, &col);
    return std::make_pair(row, col);
}