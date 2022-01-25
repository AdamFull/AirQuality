#pragma once
#include "BaseControl.h"

class CTable : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;

    void setCellValue(uint16_t row, uint16_t col, const std::string& srText);
    void setRowCount(uint16_t row_cnt);
    void setColCount(uint16_t col_cnt);
    void setColWidth(uint16_t col_id, lv_coord_t w);
    void addCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);
    void clearCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);

    std::string getCellValue(uint16_t row, uint16_t col);
    uint16_t getRowCount();
    uint16_t getColCount();
    lv_coord_t getColWidth(uint16_t col);
    bool hasCellCtrl(uint16_t row, uint16_t col, lv_table_cell_ctrl_t ctrl);
    std::pair<uint16_t, uint16_t> getSelectedCell();
};