#pragma once
#include "Arc.h"

class CCircularProgressBar : public CArc
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setValueRanged(int16_t from, int16_t to);
};