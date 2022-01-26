#pragma once
#include "BaseControl.h"

class CSlider : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;
    bool isDragged();
};