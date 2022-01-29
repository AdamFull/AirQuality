#pragma once
#include "Sensor.hpp"
#include <Adafruit_SHT31.h>
#include <memory>

class SensorSHT31 : public Sensor
{
public:
    SensorSHT31();
    void Create() override;
    void Update() override;
protected:
    std::unique_ptr<Adafruit_SHT31> m_pSensor;
    react::rfloat* reactTEMP{nullptr};
    react::rfloat* reactHUM {nullptr};
};