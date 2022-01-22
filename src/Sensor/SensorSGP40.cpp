#include "SensorSGP40.h"
#include <sstream>

void SensorSGP40::Create()
{
    m_pSensor = std::make_unique<Adafruit_SGP40>();
    m_pSensor->begin();

    m_values.emplace("sgp", &m_value);
}

void SensorSGP40::Update()
{
    m_value = m_pSensor->measureRaw();
}