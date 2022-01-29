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
    m_pSSerial = std::make_unique<SoftwareSerial>(MHZ_RX, MHZ_TX);
    m_pSSerial->begin(9600);
    m_pSensor = std::make_unique<MHZ19>();
    m_pSensor->begin(*m_pSSerial.get());
    m_pSensor->autoCalibration();
}

void SensorMHZ19::Update()
{
    (*reactPPM) = m_pSensor->getCO2();
}