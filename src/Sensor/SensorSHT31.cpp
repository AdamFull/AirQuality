#include "SensorSHT31.h"
#include <sstream>

SensorSHT31::SensorSHT31()
{
    reactTEMP = &AddValue<react::rfloat>("temp");
    reactHUM = &AddValue<react::rfloat>("hum");
}

void SensorSHT31::Create()
{
    m_pSensor = std::make_unique<Adafruit_SHT31>();
    m_pSensor->begin(0x44);
}

void SensorSHT31::Update()
{
    (*reactTEMP) = m_pSensor->readTemperature();
    (*reactHUM)= m_pSensor->readHumidity();
}