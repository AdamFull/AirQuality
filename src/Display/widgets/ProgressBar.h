#pragma once
#include "BaseControl.h"

class CProgressBar : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setValue(int32_t value, lv_anim_enable_t anim = LV_ANIM_OFF);
    void setValueRanged(int16_t from, int16_t to);
    void setStartValue(int32_t value, lv_anim_enable_t anim);
    void setRange(int32_t min, int32_t max);
    void setMode(lv_bar_mode_t mode);

    int32_t getValue();
    int32_t getStartValue();
    int32_t getMinValue();
    int32_t getMaxValue();
    lv_bar_mode_t getMode();
};