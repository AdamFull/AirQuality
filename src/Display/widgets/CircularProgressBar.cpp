#include "CircularProgressBar.h"
#include <Display/misc/Animation.h>
#include <Arduino.h>

void CCircularProgressBar::create(std::shared_ptr<CBaseControl> pParent)
{
    CArc::create(pParent);
    setRotation(90);
    setBgAngles(0, 360);
    clearFlag(LV_OBJ_FLAG_CLICKABLE);
    removeStyle(nullptr, LV_PART_KNOB);

    auto slow_inter = addAnimation("slow_inter");
    slow_inter->setTime(1000);
    slow_inter->setExecutionCallback(std::move([&](lv_anim_t* anim, int32_t value)
    {
        this->setValue(value);
    }));
}

void CCircularProgressBar::setValueRanged(int16_t from, int16_t to)
{
    auto slow_inter = getAnimation("slow_inter") ;
    slow_inter->setValues(from, to);
    slow_inter->start();
}