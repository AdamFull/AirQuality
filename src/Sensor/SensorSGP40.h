#pragma once
#include "Sensor.hpp"
#include <Adafruit_SGP40.h>
#include <memory>

class SensorSGP40 : public Sensor
{
public:
    SensorSGP40();
    void Create() override;
    void Update() override;
protected:
    std::unique_ptr<Adafruit_SGP40> m_pSensor;
    react::ruint16_t* reactTVOC{nullptr};
};