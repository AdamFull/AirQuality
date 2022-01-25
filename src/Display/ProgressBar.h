#pragma once
#include "BaseControl.h"

class CProgressBar : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;

    void setValue(int32_t value, lv_anim_enable_t anim);
    void setStartValue(int32_t value, lv_anim_enable_t anim);
    void setRange(int32_t min, int32_t max);
    void setMode(lv_bar_mode_t mode);

    int32_t getValue();
    int32_t getStartValue();
    int32_t getMinValue();
    int32_t getMaxValue();
    lv_bar_mode_t getMode();
};