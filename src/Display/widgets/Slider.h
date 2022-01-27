#pragma once
#include "BaseControl.h"

class CSlider : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;
    bool isDragged();
};