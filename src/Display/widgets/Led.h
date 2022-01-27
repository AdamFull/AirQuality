#pragma once
#include "BaseControl.h"

class CLed : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setColor(lv_color_t color);
    void setBrightness(uint8_t bright);
    void on();
    void off();
    void toggle();
    uint8_t getBrightness();
};