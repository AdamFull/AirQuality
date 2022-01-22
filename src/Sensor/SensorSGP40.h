#pragma once
#include "Sensor.hpp"
#include <Adafruit_SGP40.h>
#include <memory>

class SensorSGP40 : public Sensor
{
public:
    void Create() override;
    void Update() override;
protected:
    std::unique_ptr<Adafruit_SGP40> m_pSensor;
    uint16_t m_value;
};