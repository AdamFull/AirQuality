#pragma once
#include "Sensor.hpp"
#include <Adafruit_SHT31.h>
#include <memory>

class SensorSHT31 : public Sensor
{
public:
    void Create() override;
    void Update() override;
protected:
    std::unique_ptr<Adafruit_SHT31> m_pSensor;
    float m_temp;
    float m_humidity;
};