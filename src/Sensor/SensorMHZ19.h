#pragma once
#include "Sensor.hpp"
#include "MHZ19.h"                                        
#include <SoftwareSerial.h>
#include <memory>

class SensorMHZ19 : public Sensor
{
public:
    SensorMHZ19();
    void Create() override;
    void Update() override;
protected:
    std::unique_ptr<MHZ19> m_pSensor;
    std::unique_ptr<HardwareSerial> m_pSerial;
    react::rint32_t* reactPPM{nullptr};
};