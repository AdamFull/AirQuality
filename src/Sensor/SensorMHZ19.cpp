#include "SensorMHZ19.h"
#include <sstream>

constexpr auto MHZ_RX = D3;
constexpr auto MHZ_TX = D4;

SensorMHZ19::SensorMHZ19()
{
    reactPPM = &AddValue<react::rint32_t>("ppm");
}

void SensorMHZ19::Create()
{
    m_pSerial.reset(&Serial2);
    m_pSerial->begin(9600, SERIAL_8N1);
    m_pSensor = std::make_unique<MHZ19>();
    m_pSensor->begin(*m_pSerial.get());
    m_pSensor->autoCalibration();
}

void SensorMHZ19::Update()
{
    if (millis() - m_updateTimer > m_updateTime)
    {
        m_updateTimer = millis();
        (*reactPPM) = m_pSensor->getCO2();
    }
}