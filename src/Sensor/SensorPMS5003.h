#pragma once
#include "Sensor.hpp"
#include <SPI.h>
#include <Wire.h>
#include <memory>

enum class PMStatus
{
    eIdle,
    eRequestHeader,
    eWaitingHeader,
    eRequestBody,
    eWaitingBody,
    eFinished
};

enum class PMError
{
    eNoError,
    eTimeout,
    eInvalidHeader,
    eInvalidMessageStart,
    eMessageTooBig,
    eInvalidBody,
    eInvalidCRC,
    eUnknownSensor
};

enum class ESensorType
{
    ePLANTOWER_AUTO,             // self discovery
    ePLANTOWER_24B,              // 24 byte long message, no count info (LBC)
    ePLANTOWER_32B,              // 32 byte long message, w/count info (LBC)
    ePLANTOWER_32B_S,            // 32 byte long message, w/count info and HCHO (LBC)
    ePLANTOWER_32B_T,            // 32 byte long message, w/partial count info, temp and rhum (LBC)
    ePLANTOWER_40B,              // 40 byte long message, w/count info, temp, rhum and HCHO (LBC)
    ePMSx003 = ePLANTOWER_AUTO,   // self discovery
    ePMS1003 = ePLANTOWER_32B,    // G1
    ePMS3003 = ePLANTOWER_24B,    // G3
    ePMS5003 = ePLANTOWER_32B,    // G5
    ePMS5003S = ePLANTOWER_32B_S, // G5S
    ePMS5003T = ePLANTOWER_32B_T, // G5T
    ePMS5003ST = ePLANTOWER_40B,  // G5ST
    ePMS7003 = ePLANTOWER_32B,    // G7
    ePMSA003 = ePLANTOWER_32B     // G10
};

namespace messages
{
    constexpr const size_t head_len = 4;
    constexpr const uint8_t len = 7;
    constexpr const uint8_t sleep[len] = {0x42,0x4D,0xE4,0x00,0x00,0x01,0x73};
    constexpr const uint8_t wake[len] = {0x42,0x4D,0xE4,0x00,0x01,0x01,0x74};
    constexpr const uint8_t config[len] = {0x42, 0x4D, 0xE1, 0x00, 0x00, 0x01, 0x70};
    constexpr const uint8_t trigger[len] = {0x42, 0x4D, 0xE2, 0x00, 0x00, 0x01, 0x71};

    constexpr const uint16_t max_wait_time = 1000;
    constexpr const uint8_t buffer_len = 40;

    constexpr const uint8_t TSI_START = 4;  // PM [ug/m3] (TSI standard)
    constexpr const uint8_t ATM_START = 10; // PM [ug/m3] (std. atmosphere)
    constexpr const uint8_t NUM_START = 16; // num. particles in 100 cm3 of air
}

#define PMS_ERROR_TIMEOUT "Sensor read timeout"
#define PMS_ERROR_PMS_TYPE "Wrong PMSx003 sensor type"
#define PMS_ERROR_MSG_UNKNOWN "Unknown message protocol"
#define PMS_ERROR_MSG_HEADER "Incomplete message header"
#define PMS_ERROR_MSG_BODY "Incomplete message body"
#define PMS_ERROR_MSG_START "Wrong message start"
#define PMS_ERROR_MSG_LENGTH "Message too long"
#define PMS_ERROR_MSG_CKSUM "Wrong message checksum"

class SensorPMS5003 : public Sensor
{
public:
    static constexpr const char* VAL_PM01 = "pm01";
    static constexpr const char* VAL_PM10 = "pm10";
    static constexpr const char* VAL_PM25 = "pm25";

    SensorPMS5003();

    void Create() override;
    void Update() override;
private:
    void RequestHeader();
    void WaitHeader();
    void RequestBody();
    void WaitBody();
    void Finalize(bool tsi_mode, bool truncated_num);

    inline bool has_number_concentration() { return (eSensorType != ESensorType::ePMS3003); }
    inline bool has_temperature_humidity() { return (eSensorStatus == PMStatus::eFinished) && ((eSensorType == ESensorType::ePMS5003T) || (eSensorType == ESensorType::ePMS5003ST)); }
    inline bool has_formaldehyde() { return (eSensorStatus == PMStatus::eFinished) && ((eSensorType == ESensorType::ePMS5003S) || (eSensorType == ESensorType::ePMS5003ST)); }

    inline uint16_t buff2word(uint8_t n) { return (m_buffer[n] << 8) | m_buffer[n + 1]; }
    bool crc(size_t len);

    union
    {
        uint16_t data[9]; // all PM/NC data
        struct
        {
            uint16_t pm[3]; // particulate matter [ug/m3]
            uint16_t nc[6]; // number concentration [#/100cc]
        };
        struct
        {
            // pmX [ug/m3]: PM1.0, PM2.5 & PM10
            uint16_t pm01, pm25, pm10;
            // nXpY [#/100cc]: number concentrations under X.Y um
            uint16_t n0p3, n0p5, n1p0, n2p5, n5p0, n10p0;
        };
    };
    union
    {
        float extra[3]; // T/RH/HCHO
        struct
        {
            // temperature [°C], relative humidity [%], formaldehyde concentration [mg/m3]
            float temp, rhum, hcho;
        };
    };
protected:
    std::unique_ptr<HardwareSerial> m_pSerial;
    PMStatus eSensorStatus{PMStatus::eIdle};
    PMError eError{PMError::eNoError};
    ESensorType eSensorType;
    uint32_t m_iStartWait{0}, m_iWaitTime{0};

    react::ruint16_t* reactPM01{nullptr};
    react::ruint16_t* reactPM10{nullptr};
    react::ruint16_t* reactPM25{nullptr};

    size_t m_iBodyLen{0};
    size_t m_iMessageLen{0};
    float temp_offset = 0.0;
    float rhum_offset = 0.0;
    uint8_t m_buffer[messages::buffer_len], nbytes;
};