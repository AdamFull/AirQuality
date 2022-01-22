#include "SensorSHT31.h"
#include <sstream>

void SensorSHT31::Create()
{
    m_pSensor = std::make_unique<Adafruit_SHT31>();
    m_pSensor->begin(0x44);

    m_values.emplace("temp", &m_temp);
    m_values.emplace("hum", &m_humidity);
}

void SensorSHT31::Update()
{
    m_temp = m_pSensor->readTemperature();
    m_humidity = m_pSensor->readHumidity();
}