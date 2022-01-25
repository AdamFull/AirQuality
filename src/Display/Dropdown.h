#pragma once
#include "BaseControl.h"

class CDropdown : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;

    void setText(const std::string& srText);
    void setOptions(const std::string& srText);
    void setOptionsStatic(const std::string& srText);
    void addOption(const std::string& srText, uint32_t pos);
    void clearOptions();
    void setSelected(uint16_t sel_opt);
    void setDir(lv_dir_t dir);
    void setSelectedHighlight(bool en);
};