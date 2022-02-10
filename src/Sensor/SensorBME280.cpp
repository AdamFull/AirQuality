#include "SensorBME280.h"
#include <sstream>

SensorBME280::SensorBME280()
{
    reactTEMP = &AddValue<react::rfloat>("temp");
    reactHUM = &AddValue<react::rfloat>("hum");
    reactPressure = &AddValue<react::rfloat>("press");
}

void SensorBME280::Create()
{
    //m_pInterface = std::make_unique<TwoWire>(PB7, PB6);

    auto result = read8(Registers::BME280_REGISTER_CHIPID);
    if (result != 0x60)
    {
        Serial.println(result);
        if(m_errorCallback) m_errorCallback("BME280: sensor was not found.");
        return;
    }

    Serial.println("Reading calib");

    m_calibration.dig_T1 = read16_LE(Registers::BME280_REGISTER_DIG_T1);
    m_calibration.dig_T2 = readS16_LE(Registers::BME280_REGISTER_DIG_T2);
    m_calibration.dig_T3 = readS16_LE(Registers::BME280_REGISTER_DIG_T3);

    m_calibration.dig_P1 = read16_LE(Registers::BME280_REGISTER_DIG_P1);
    m_calibration.dig_P2 = readS16_LE(Registers::BME280_REGISTER_DIG_P2);
    m_calibration.dig_P3 = readS16_LE(Registers::BME280_REGISTER_DIG_P3);
    m_calibration.dig_P4 = readS16_LE(Registers::BME280_REGISTER_DIG_P4);
    m_calibration.dig_P5 = readS16_LE(Registers::BME280_REGISTER_DIG_P5);
    m_calibration.dig_P6 = readS16_LE(Registers::BME280_REGISTER_DIG_P6);
    m_calibration.dig_P7 = readS16_LE(Registers::BME280_REGISTER_DIG_P7);
    m_calibration.dig_P8 = readS16_LE(Registers::BME280_REGISTER_DIG_P8);
    m_calibration.dig_P9 = readS16_LE(Registers::BME280_REGISTER_DIG_P9);

    m_calibration.dig_H1 = read8(Registers::BME280_REGISTER_DIG_H1);
    m_calibration.dig_H2 = readS16_LE(Registers::BME280_REGISTER_DIG_H2);
    m_calibration.dig_H3 = read8(Registers::BME280_REGISTER_DIG_H3);
    m_calibration.dig_H4 = (read8(Registers::BME280_REGISTER_DIG_H4) << 4) | (read8(Registers::BME280_REGISTER_DIG_H4+1) & 0xF);
    m_calibration.dig_H5 = (read8(Registers::BME280_REGISTER_DIG_H5+1) << 4) | (read8(Registers::BME280_REGISTER_DIG_H5) >> 4);
    m_calibration.dig_H6 = (int8_t)read8(Registers::BME280_REGISTER_DIG_H6);

    write8(Registers::BME280_REGISTER_CONTROLHUMID, 0x03); // Set before CONTROL (DS 5.4.3)
    write8(Registers::BME280_REGISTER_CONTROL, 0x3F);
}

void SensorBME280::Update()
{
    if (millis() - m_updateTimer > m_updateTime)
    {
        m_updateTimer = millis();

        // Read temperature
        int32_t adc_T = read16(Registers::BME280_REGISTER_TEMPDATA);
        adc_T <<= 8;
        adc_T |= read8(Registers::BME280_REGISTER_TEMPDATA + 2);
        adc_T >>= 4;

        int32_t var1t = ((((adc_T >> 3) - ((int32_t)m_calibration.dig_T1 << 1))) *
                         ((int32_t)m_calibration.dig_T2)) >>
                        11;

        int32_t var2t = (((((adc_T >> 4) - ((int32_t)m_calibration.dig_T1)) *
                           ((adc_T >> 4) - ((int32_t)m_calibration.dig_T1))) >>
                          12) *
                         ((int32_t)m_calibration.dig_T3)) >>
                        14;

        int32_t t_fine = var1t + var2t;

        float T = (t_fine * 5 + 128) >> 8;
        (*reactTEMP) = T / 100.f;

        // Read pressure
        int64_t var1, var2, p;

        int32_t adc_P = read16(Registers::BME280_REGISTER_PRESSUREDATA);
        adc_P <<= 8;
        adc_P |= read8(Registers::BME280_REGISTER_PRESSUREDATA + 2);
        adc_P >>= 4;

        var1 = ((int64_t)t_fine) - 128000;
        var2 = var1 * var1 * (int64_t)m_calibration.dig_P6;
        var2 = var2 + ((var1 * (int64_t)m_calibration.dig_P5) << 17);
        var2 = var2 + (((int64_t)m_calibration.dig_P4) << 35);
        var1 = ((var1 * var1 * (int64_t)m_calibration.dig_P3) >> 8) +
               ((var1 * (int64_t)m_calibration.dig_P2) << 12);
        var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)m_calibration.dig_P1) >> 33;

        if (var1 == 0)
        {
            // return 0;  // avoid exception caused by division by zero
            return; // avoid exception caused by division by zero
        }
        p = 1048576 - adc_P;
        p = (((p << 31) - var2) * 3125) / var1;
        var1 = (((int64_t)m_calibration.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
        var2 = (((int64_t)m_calibration.dig_P8) * p) >> 19;

        p = ((p + var1 + var2) >> 8) + (((int64_t)m_calibration.dig_P7) << 4);
        (*reactPressure) = (float)p / 256;

        // Read humidity
        int32_t adc_H = read16(Registers::BME280_REGISTER_HUMIDDATA);

        int32_t v_x1_u32r;

        v_x1_u32r = (t_fine - ((int32_t)76800));

        v_x1_u32r = (((((adc_H << 14) - (((int32_t)m_calibration.dig_H4) << 20) -
                        (((int32_t)m_calibration.dig_H5) * v_x1_u32r)) +
                       ((int32_t)16384)) >>
                      15) *
                     (((((((v_x1_u32r * ((int32_t)m_calibration.dig_H6)) >> 10) *
                          (((v_x1_u32r * ((int32_t)m_calibration.dig_H3)) >> 11) + ((int32_t)32768))) >>
                         10) +
                        ((int32_t)2097152)) *
                           ((int32_t)m_calibration.dig_H2) +
                       8192) >>
                      14));

        v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) *
                                   ((int32_t)m_calibration.dig_H1)) >>
                                  4));

        v_x1_u32r = (v_x1_u32r < 0) ? 0 : v_x1_u32r;
        v_x1_u32r = (v_x1_u32r > 419430400) ? 419430400 : v_x1_u32r;
        float h = (v_x1_u32r >> 12);
        (*reactHUM) = h / 1024.f;
    }
}

void SensorBME280::write8(uint8_t reg, uint8_t value)
{
    Wire.beginTransmission(Registers::_device);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

uint8_t SensorBME280::read8(uint8_t reg)
{
    uint8_t value;

    Wire.beginTransmission(Registers::_device);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(Registers::_device, (uint8_t)1);
    value = Wire.read();
    Wire.endTransmission();

    return value;
}

uint16_t SensorBME280::read16(uint8_t reg)
{
    uint16_t value;

    Wire.beginTransmission(Registers::_device);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(Registers::_device, (uint8_t)2);
    value = (Wire.read() << 8) | Wire.read();
    Wire.endTransmission();

    return value;
}

uint16_t SensorBME280::read16_LE(uint8_t reg)
{
    uint16_t temp = read16(reg);
    return (temp >> 8) | (temp << 8);
}

int16_t SensorBME280::readS16(uint8_t reg)
{
    return (int16_t)read16(reg);
}

int16_t SensorBME280::readS16_LE(uint8_t reg)
{
    return (int16_t)read16_LE(reg);
}
