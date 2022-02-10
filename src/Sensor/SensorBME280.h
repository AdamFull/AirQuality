#pragma once
#include "Sensor.hpp"
#include <memory>
#include <Wire.h>

namespace Registers
{
    constexpr uint8_t BME280_REGISTER_DIG_T1 = 0x88;
    constexpr uint8_t BME280_REGISTER_DIG_T2 = 0x8A;
    constexpr uint8_t BME280_REGISTER_DIG_T3 = 0x8C;

    constexpr uint8_t BME280_REGISTER_DIG_P1 = 0x8E;
    constexpr uint8_t BME280_REGISTER_DIG_P2 = 0x90;
    constexpr uint8_t BME280_REGISTER_DIG_P3 = 0x92;
    constexpr uint8_t BME280_REGISTER_DIG_P4 = 0x94;
    constexpr uint8_t BME280_REGISTER_DIG_P5 = 0x96;
    constexpr uint8_t BME280_REGISTER_DIG_P6 = 0x98;
    constexpr uint8_t BME280_REGISTER_DIG_P7 = 0x9A;
    constexpr uint8_t BME280_REGISTER_DIG_P8 = 0x9C;
    constexpr uint8_t BME280_REGISTER_DIG_P9 = 0x9E;

    constexpr uint8_t BME280_REGISTER_DIG_H1 = 0xA1;
    constexpr uint8_t BME280_REGISTER_DIG_H2 = 0xE1;
    constexpr uint8_t BME280_REGISTER_DIG_H3 = 0xE3;
    constexpr uint8_t BME280_REGISTER_DIG_H4 = 0xE4;
    constexpr uint8_t BME280_REGISTER_DIG_H5 = 0xE5;
    constexpr uint8_t BME280_REGISTER_DIG_H6 = 0xE7;

    constexpr uint8_t BME280_REGISTER_CHIPID = 0xD0;
    constexpr uint8_t BME280_REGISTER_VERSION = 0xD1;
    constexpr uint8_t BME280_REGISTER_SOFTRESET = 0xE0;

    constexpr uint8_t BME280_REGISTER_CAL26 = 0xE1;  // R calibration stored in 0xE1-0xF0

    constexpr uint8_t BME280_REGISTER_CONTROLHUMID = 0xF2;
    constexpr uint8_t BME280_REGISTER_CONTROL = 0xF4;
    constexpr uint8_t BME280_REGISTER_CONFIG = 0xF5;
    constexpr uint8_t BME280_REGISTER_PRESSUREDATA = 0xF7;
    constexpr uint8_t BME280_REGISTER_TEMPDATA = 0xFA;
    constexpr uint8_t BME280_REGISTER_HUMIDDATA = 0xFD;
    constexpr uint8_t _device = 0x76;
}

class SensorBME280 : public Sensor
{
    struct FCalibrationData
    {
    uint16_t dig_T1;
    int16_t  dig_T2;
    int16_t  dig_T3;

    uint16_t dig_P1;
    int16_t  dig_P2;
    int16_t  dig_P3;
    int16_t  dig_P4;
    int16_t  dig_P5;
    int16_t  dig_P6;
    int16_t  dig_P7;
    int16_t  dig_P8;
    int16_t  dig_P9;

    uint8_t  dig_H1;
    int16_t  dig_H2;
    uint8_t  dig_H3;
    int16_t  dig_H4;
    int16_t  dig_H5;
    int8_t   dig_H6;
    };
public:
    SensorBME280();
    void Create() override;
    void Update() override;
private:
    void write8(uint8_t reg, uint8_t value);
    uint8_t read8(uint8_t reg);
    uint16_t read16(uint8_t reg);
    uint16_t read16_LE(uint8_t reg);
    int16_t readS16(uint8_t reg);
    int16_t readS16_LE(uint8_t reg);
protected:
    std::shared_ptr<TwoWire> m_pInterface;
    react::rfloat* reactTEMP{nullptr};
    react::rfloat* reactHUM {nullptr};
    react::rfloat* reactPressure {nullptr};

    FCalibrationData m_calibration;
};