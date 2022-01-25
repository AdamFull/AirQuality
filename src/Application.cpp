#include "Application.h"
#include "Sensor/SensorHandler.hpp"
#include "Sensor/SensorPMS5003.h"
#include "Sensor/SensorMHZ19.h"
#include "Sensor/SensorSGP40.h"
#include "Sensor/SensorSHT31.h"

void Application::Create()
{
    display = std::make_unique<DisplayHandler>();

    auto labelPM25 = display->AddControl<CLabel>("labelPM25");
    auto labelPM25data = display->AddControl<CLabel>("labelPM25data");
    auto progressPM25 = display->AddControl<CProgressBar>("progressPM25");
    
    auto labelTVOC = display->AddControl<CLabel>("labelTVOC");
    auto labelTVOCdata = display->AddControl<CLabel>("labelTVOCdata");
    auto progressTVOC = display->AddControl<CProgressBar>("progressTVOC");

    auto labelCO2 = display->AddControl<CLabel>("labelCO2");
    auto labelCO2data = display->AddControl<CLabel>("labelCO2data");
    auto progressCO2 = display->AddControl<CProgressBar>("progressCO2");

    auto labelTemp = display->AddControl<CLabel>("labelTemp");
    auto labelTempdata = display->AddControl<CLabel>("labelTempdata");
    auto progressTemp = display->AddControl<CProgressBar>("progressTemp");

    auto labelHum = display->AddControl<CLabel>("labelHum");
    auto labelHumdata = display->AddControl<CLabel>("labelHumdata");
    auto progressHum = display->AddControl<CProgressBar>("progressHum");
    
    display->Create();

    labelPM25->setStyleTextFont(&lv_font_montserrat_12, 0);
    labelPM25->setAlign(LV_ALIGN_TOP_LEFT, 0, 0);
    labelPM25->setText("PM2.5");

    labelPM25data->setStyleTextFont(&lv_font_montserrat_40, 0);
    labelPM25data->setAlign(LV_ALIGN_TOP_LEFT, 0, 10);

    progressPM25->setAlign(LV_ALIGN_TOP_LEFT, 0, 50);
    progressPM25->setWidth(320);


    labelTVOC->setStyleTextFont(&lv_font_montserrat_12, 0);
    labelTVOC->setAlign(LV_ALIGN_LEFT_MID, 0, 0);
    labelTVOC->setText("tVOC");

    labelTVOCdata->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelTVOCdata->setAlign(LV_ALIGN_LEFT_MID, 0, 20);

    progressTVOC->setAlign(LV_ALIGN_LEFT_MID, 0, 40);
    progressTVOC->setWidth(150);


    labelCO2->setStyleTextFont(&lv_font_montserrat_12, 0);
    labelCO2->setAlign(LV_ALIGN_RIGHT_MID, 0, 0);
    labelCO2->setText("CO2");

    labelCO2data->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelCO2data->setAlign(LV_ALIGN_RIGHT_MID, 0, 20);

    progressCO2->setAlign(LV_ALIGN_RIGHT_MID, 0, 40);
    progressCO2->setWidth(150);


    labelTemp->setStyleTextFont(&lv_font_montserrat_12, 0);
    labelTemp->setAlign(LV_ALIGN_LEFT_MID, 0, 60);
    labelTemp->setText("Temp");

    labelTempdata->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelTempdata->setAlign(LV_ALIGN_LEFT_MID, 0, 80);

    progressTemp->setAlign(LV_ALIGN_LEFT_MID, 0, 100);
    progressTemp->setWidth(150);


    labelHum->setStyleTextFont(&lv_font_montserrat_12, 0);
    labelHum->setAlign(LV_ALIGN_RIGHT_MID, 0, 60);
    labelHum->setText("Hum");

    labelHumdata->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelHumdata->setAlign(LV_ALIGN_RIGHT_MID, 0, 80);

    progressHum->setAlign(LV_ALIGN_RIGHT_MID, 0, 100);
    progressHum->setWidth(150);

    sensor_pm25.bind(std::move([=](const uint16_t &val)
    {
        Serial.println(val);
        auto sr = std::string(String(val).c_str());
        labelPM25data->setText(sr);
        progressPM25->setValue(val/2300.0 * 100, LV_ANIM_ON);
    }));

    SensorHandler::GetInstance()->AddSensor<SensorPMS5003>("pms5003");
    SensorHandler::GetInstance()->GetLast()->AttachErrorCB(std::move([&](const std::string& error) { ErrorHandler(error); }));
    SensorHandler::GetInstance()->AddSensor<SensorMHZ19>("MH-Z19");
    SensorHandler::GetInstance()->AddSensor<SensorSGP40>("SGP40");
    SensorHandler::GetInstance()->AddSensor<SensorSHT31>("SHT31");
    
    SensorHandler::GetInstance()->Create();
}

void Application::Update()
{
    display->Update();
    SensorHandler::GetInstance()->Update();
    sensor_pm25 = SensorHandler::GetInstance()->GetSensor("pms5003")->GetValue<uint16_t>("pm25");
}

void Application::ErrorHandler(const std::string& error)
{
    Serial.println(error.c_str());
}