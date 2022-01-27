#pragma once
#include "BaseControl.h"

class CButtonMatrix : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setMap(const char * map[]);
    void setCtrlMap(const lv_btnmatrix_ctrl_t ctrl_map[]);
    void setSelectedButton(uint16_t btn_id);
    void setButtonCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);
    void clearButtonCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);
    void setButtonCtrlAll(lv_btnmatrix_ctrl_t ctrl);
    void clearButtonCtrlAll(lv_btnmatrix_ctrl_t ctrl);
    void setButtonWidth(uint16_t btn_id, uint8_t width);
    void setOneChecked(bool en);
    const char** getMap();
    uint16_t getSelectedButton();
    const char* getButtonText(uint16_t btn_id);
    bool hasButtonCtrl(uint16_t btn_id, lv_btnmatrix_ctrl_t ctrl);
    bool getOneChecked();
};