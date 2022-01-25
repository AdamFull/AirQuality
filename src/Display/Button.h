#pragma once
#include "BaseControl.h"

class CButton : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;
};