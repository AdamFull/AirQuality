#pragma once
#include "Sensor.hpp"
#include <SPI.h>
#include <Wire.h>
#include <PMserial.h>
#include <memory>

class SensorPMS5003 : public Sensor
{
public:
    void Create() override;
    void Update() override;
protected:
    std::unique_ptr<SerialPM> m_pSensor;
};