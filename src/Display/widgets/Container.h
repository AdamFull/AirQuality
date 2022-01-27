#pragma once
#include "BaseControl.h"

class CContainer : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent = nullptr) override;
};