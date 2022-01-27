#pragma once
#include "BaseControl.h"

class CMenu : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;
};