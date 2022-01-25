#pragma once
#include "BaseControl.h"

class CSwitch : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;
};