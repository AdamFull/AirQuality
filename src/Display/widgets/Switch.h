#pragma once
#include "BaseControl.h"

class CSwitch : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;
};