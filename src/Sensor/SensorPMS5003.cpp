#include "SensorPMS5003.h"
#include <sstream>

constexpr auto PMS_RX = PA11;
constexpr auto PMS_TX = PA12;

void SensorPMS5003::Create()
{
    //m_pSensor = std::make_unique<SerialPM>(PMS5003, PMS_RX, PMS_TX);
    pinMode(PA8, OUTPUT);
    digitalWrite(PA8, HIGH);
    m_pSerial.reset(&Serial1);
    m_pSerial->begin(9600, SERIAL_8N1);

    m_pSerial->write(messages::config, messages::len);
    m_pSerial->flush();
    delay(2000);
    while (m_pSerial->available())
        m_pSerial->read();

    /*m_pSensor = std::make_unique<SerialPM>(PMS5003, Serial1);
    m_pSensor->init();*/

    m_values.emplace("pm01", &pm01);
    m_values.emplace("pm10", &pm10);
    m_values.emplace("pm25", &pm25);
}

void SensorPMS5003::Update()
{
    switch (eSensorStatus)
    {
    case PMStatus::eIdle:
        RequestHeader();
        break;
    case PMStatus::eWaitingHeader:
        WaitHeader();
        break;
    case PMStatus::eRequestBody:
        RequestBody();
        break;
    case PMStatus::eWaitingBody:
        WaitBody();
        break;
    case PMStatus::eFinished:
        Finalize(false, false);
        break;
    }

    if(eError != PMError::eNoError && m_errorCallback)
    {
        std::stringstream ss;
        ss << "PMS5003: ";
        switch (eError)
        {
        case PMError::eTimeout: ss << PMS_ERROR_TIMEOUT; break;
        //case PMError::eUnknownSensor: ss << PMS_ERROR_MSG_UNKNOWN; break;
        case PMError::eInvalidHeader: ss << PMS_ERROR_MSG_HEADER; break;
        case PMError::eInvalidBody:  ss << PMS_ERROR_MSG_BODY; break;
        case PMError::eInvalidMessageStart:  ss << PMS_ERROR_MSG_START; break;
        case PMError::eMessageTooBig:  ss << PMS_ERROR_MSG_LENGTH; break;
        case PMError::eInvalidCRC:  ss << PMS_ERROR_MSG_CKSUM; break;
        case PMError::eUnknownSensor:  ss << PMS_ERROR_PMS_TYPE; break;
        default: ss << "Unknown error."; break;
        }
        eError = PMError::eNoError;
        m_errorCallback(ss.str());
    }
}

void SensorPMS5003::RequestHeader()
{
    while (m_pSerial->available())
        m_pSerial->read();
    m_pSerial->write(messages::trigger, messages::len);
    m_pSerial->flush();

    m_iStartWait = millis();
    eSensorStatus = PMStatus::eWaitingHeader;
}

void SensorPMS5003::WaitHeader()
{
    if(size_t(m_pSerial->available()) < messages::head_len && m_iWaitTime < messages::max_wait_time)
        m_iWaitTime = millis() - m_iStartWait;
    else
    {
        if(!m_pSerial->available())
        {
            eSensorStatus = PMStatus::eIdle;
            eError = PMError::eTimeout;
            return;
        }

        nbytes = m_pSerial->readBytes(&m_buffer[0], messages::head_len);
        if (nbytes != messages::head_len)
        {
            eSensorStatus = PMStatus::eIdle;
            eError = PMError::eInvalidHeader;
            return;
        }

        if (buff2word(0) != 0x424D)
        {
            eSensorStatus = PMStatus::eIdle;
            eError = PMError::eInvalidMessageStart;
            return;
        }

        eSensorStatus = PMStatus::eRequestBody;
    }
}

void SensorPMS5003::RequestBody()
{
    m_iBodyLen = buff2word(2);
    m_iMessageLen = messages::head_len + m_iBodyLen;

    switch (m_iMessageLen)
    {
    case 24:
        eSensorType = ESensorType::ePLANTOWER_24B;
        break;
    case 32:
        eSensorType = ESensorType::ePLANTOWER_32B;
        break;
    case 40:
        eSensorType = ESensorType::ePLANTOWER_40B;
        break;
    default:
        eSensorStatus = PMStatus::eIdle;
        eError = PMError::eUnknownSensor;
        return;
        break;
    }

    if(m_iMessageLen > messages::buffer_len)
    {
        eSensorStatus = PMStatus::eIdle;
        eError = PMError::eMessageTooBig;
        return;
    }

    eSensorStatus = PMStatus::eWaitingBody;
}

void SensorPMS5003::WaitBody()
{
    if(size_t(m_pSerial->available()) < m_iBodyLen && m_iWaitTime < messages::max_wait_time)
        m_iWaitTime = millis() - m_iStartWait;
    else
    {
        if(!m_pSerial->available())
        {
            eSensorStatus = PMStatus::eIdle;
            eError = PMError::eTimeout;
            return;
        }

        nbytes += m_pSerial->readBytes(&m_buffer[messages::head_len], m_iBodyLen);
        if (nbytes != m_iMessageLen)
        {
            eSensorStatus = PMStatus::eIdle;
            eError = PMError::eInvalidBody;
            return;
        }

        if (!crc(m_iMessageLen))
        {
            eSensorStatus = PMStatus::eIdle;
            eError = PMError::eInvalidCRC;
            return;
        }

        eSensorStatus = PMStatus::eFinished;
    }
}

void SensorPMS5003::Finalize(bool tsi_mode = false, bool truncated_num = false)
{
    uint8_t bin, n;
        
    for (bin = 0, n = tsi_mode ? messages::TSI_START : messages::ATM_START; bin < 3; bin++, n += 2)
    {
        pm[bin] = buff2word(n);
    }

    if (!has_number_concentration())
    {
        eSensorStatus = PMStatus::eIdle;
        return;
    }
        
    for (bin = 0, n = messages::NUM_START; bin < 6; bin++, n += 2)
    {
        nc[bin] = buff2word(n); // number particles w/diameter > r_bin
    }

    switch (eSensorType)
    {
    case ESensorType::ePMS5003S:
        hcho = buff2word(28) * 1e-3;
        break;
    case ESensorType::ePMS5003T:
        temp = int16_t(n5p0) * 1e-1 + temp_offset; // cast to signed integer 16bits
        rhum = n10p0 * 1e-1 + rhum_offset;
        n5p0 = 0;
        n10p0 = 0;
        break;
    case ESensorType::ePMS5003ST:
        hcho = buff2word(28) * 1e-3;
        temp = int16_t(buff2word(30)) * 1e-1 + temp_offset; // cast to signed integer 16bits
        rhum = buff2word(32) * 1e-1 + rhum_offset;
        break;
    default:
        break;
    }

    if (!truncated_num)
    {
        eSensorStatus = PMStatus::eIdle;
        return;
    }
        
    for (bin = 0; bin < 5; bin++)
    {
        nc[bin] -= nc[bin + 1]; // de-accumulate number concentrations
    }

    eSensorStatus = PMStatus::eIdle;
}

bool SensorPMS5003::crc(size_t len)
{
  uint16_t cksum = buff2word(len - 2);
  for (uint8_t n = 0; n < len - 2; n++)
  {
    cksum -= m_buffer[n];
  }

  return (cksum == 0);
}