#pragma once
#include "BaseControl.h"
#include <vector>

class CLine : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void addPoint(int16_t x, int16_t y);
    void removePoint(uint32_t pos);
    void clear();

    void update();
    void setInvertY(bool en);

    bool isInvertY();
private:
    std::vector<lv_point_t> vPoints;
};