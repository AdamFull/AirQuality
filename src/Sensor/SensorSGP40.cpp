#include "SensorSGP40.h"
#include <sstream>

SensorSGP40::SensorSGP40()
{
    reactTVOC = &AddValue<react::ruint16_t>("tvoc");
}

void SensorSGP40::Create()
{
    m_pSensor = std::make_unique<Adafruit_SGP40>();
    m_pSensor->begin();
}

void SensorSGP40::Update()
{
    if (millis() - m_updateTimer > m_updateTime)
    {
        m_updateTimer = millis();
        (*reactTVOC) = m_pSensor->measureRaw() / 1000;
    }
}