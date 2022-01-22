#pragma once
#include "Sensor.hpp"
#include "MHZ19.h"                                        
#include <SoftwareSerial.h>
#include <memory>

class SensorMHZ19 : public Sensor
{
public:
    void Create() override;
    void Update() override;
protected:
    std::unique_ptr<MHZ19> m_pSensor;
    std::unique_ptr<SoftwareSerial> m_pSSerial;
    int m_value;
};