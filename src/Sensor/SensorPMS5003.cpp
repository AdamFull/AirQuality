#include "SensorPMS5003.h"
#include <sstream>

constexpr auto PMS_RX = PA11;
constexpr auto PMS_TX = PA12;

void SensorPMS5003::Create()
{
    //m_pSensor = std::make_unique<SerialPM>(PMS5003, PMS_RX, PMS_TX);
    pinMode(PB8, OUTPUT);
    digitalWrite(PB8, HIGH);
    m_pSensor = std::make_unique<SerialPM>(PMS5003, Serial1);
    m_pSensor->init();

    m_values.emplace("pm01", &m_pSensor->pm01);
    m_values.emplace("pm10", &m_pSensor->pm10);
    m_values.emplace("pm25", &m_pSensor->pm25);
}

void SensorPMS5003::Update()
{
    auto status = m_pSensor->read();
    if(status != SerialPM::STATUS::OK && m_errorCallback)
    {
        std::stringstream ss;
        ss << "PMS5003: ";
        switch (m_pSensor->status)
        {
        case SerialPM::STATUS::ERROR_TIMEOUT: ss << PMS_ERROR_TIMEOUT; break;
        case SerialPM::STATUS::ERROR_MSG_UNKNOWN: ss << PMS_ERROR_MSG_UNKNOWN; break;
        case SerialPM::STATUS::ERROR_MSG_HEADER: ss << PMS_ERROR_MSG_HEADER; break;
        case SerialPM::STATUS::ERROR_MSG_BODY:  ss << PMS_ERROR_MSG_BODY; break;
        case SerialPM::STATUS::ERROR_MSG_START:  ss << PMS_ERROR_MSG_START; break;
        case SerialPM::STATUS::ERROR_MSG_LENGTH:  ss << PMS_ERROR_MSG_LENGTH; break;
        case SerialPM::STATUS::ERROR_MSG_CKSUM:  ss << PMS_ERROR_MSG_CKSUM; break;
        case SerialPM::STATUS::ERROR_PMS_TYPE:  ss << PMS_ERROR_PMS_TYPE; break;
        default: ss << "Unknown error."; break;
        }

        m_errorCallback(ss.str());
    }
}