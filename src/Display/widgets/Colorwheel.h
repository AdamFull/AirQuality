#pragma once
#include "BaseControl.h"

class CColorwheel : public CBaseControl
{
public:
    CColorwheel(bool knob_recolor);
    void create(std::shared_ptr<CBaseControl> pParent) override;

    bool setHsv(lv_color_hsv_t hsv);
    bool setRgb(lv_color_t color);
    void setMode(lv_colorwheel_mode_t mode);
    void setModeFixed(bool fixed);
    lv_color_hsv_t getHsv();
    lv_color_t getRgb();
    lv_colorwheel_mode_t getColorMode();
    bool getColorModeFixed();
private:
    bool m_bKnobRecolor{true};
};
