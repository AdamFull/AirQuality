#pragma once
#include "BaseControl.h"

class CArc : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;

    void setStartAngle(uint16_t start);
    void setEndAngle(uint16_t end);
    void setAngles(uint16_t start, uint16_t end);
    void setBgStartAngle(uint16_t start);
    void setBgEndAngle(uint16_t end);
    void setBgAngles(uint16_t start, uint16_t end);
    void setRotation(uint16_t rotation);
    void setMode(lv_arc_mode_t type);
    void setValue(int16_t value);
    void setRange(int16_t min, int16_t max);
    void setChangeRate(uint16_t rate);

    uint16_t getAngleStart();
    uint16_t getAngleEnd();
    uint16_t getBgAngleStart();
    uint16_t getBgAngleEnd();
    int16_t getValue();
    int16_t getMinValue();
    int16_t getMaxValue();
    lv_arc_mode_t getMode();
};