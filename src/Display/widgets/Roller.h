#pragma once
#include "BaseControl.h"

class CRoller : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setOptions(const std::string& srOpt, lv_roller_mode_t mode);
    void setSelected(uint16_t sel_opt, lv_anim_enable_t anim);
    void setVisibleRowCount(uint8_t row_cnt);

    uint16_t getSelected();
    std::string getSelectedStr();
    std::string getOptions();
    uint16_t getOptionCount();
};