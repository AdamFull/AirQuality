#pragma once
#include "BaseControl.h"

class CSpinner : public CBaseControl
{
public:
    CSpinner(uint32_t time, uint32_t arc_length);
    void create(std::shared_ptr<CBaseControl> pParent) override;
private:
    uint32_t m_timeMs{1000};
    uint32_t m_arcLength{60};
};