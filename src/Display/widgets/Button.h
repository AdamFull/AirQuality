#pragma once
#include "BaseControl.h"

class CButton : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;
    void create(std::shared_ptr<CBaseControl>, std::shared_ptr<CBaseControl> pPtr) override; 
};