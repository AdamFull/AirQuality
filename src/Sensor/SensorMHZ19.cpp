#include "SensorMHZ19.h"
#include <sstream>

constexpr auto MHZ_RX = D3;
constexpr auto MHZ_TX = D4;

void SensorMHZ19::Create()
{
    m_pSSerial = std::make_unique<SoftwareSerial>(MHZ_RX, MHZ_TX);
    m_pSSerial->begin(9600);
    m_pSensor = std::make_unique<MHZ19>();
    m_pSensor->begin(*m_pSSerial.get());
    m_pSensor->autoCalibration();

    m_values.emplace("ppm", &m_value);
}

void SensorMHZ19::Update()
{
    m_value = m_pSensor->getCO2();
}