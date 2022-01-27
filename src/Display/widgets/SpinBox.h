#pragma once
#include "BaseControl.h"

class CSpinbox : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setValue(int32_t i);
    void setRollover(bool b);
    void setDigitFormat(uint8_t digit_count, uint8_t separator_position);
    void setStep(uint32_t step);
    void setRange(int32_t range_min, int32_t range_max);
    void setPos(uint8_t pos);
    void setDigitStepDirection(lv_dir_t direction);
    int32_t getValue();
    int32_t getStep();
    void stepNext();
    void stepPrev();
    bool getRollover();
    void increment();
    void decrement();
};