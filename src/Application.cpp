#include "Application.h"
#include "Sensor/SensorHandler.hpp"
#include "Sensor/SensorPMS5003.h"
#include "Sensor/SensorMHZ19.h"
#include "Sensor/SensorSGP40.h"
#include "Sensor/SensorSHT31.h"

void Application::Create()
{
    display = std::make_unique<DisplayHandler>();

    auto mainScreen = display->AddControl<CBaseControl>("main");

    auto delimeter = display->AddControl<CLine>("delimeter");

    auto labelPM25 = display->AddControl<CLabel>("labelPM25");
    auto labelPM25data = display->AddControl<CLabel>("labelPM25data");
    auto progressPM25 = display->AddControl<CArc>("progressPM25");
    
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

    auto small_text_style = display->AddStyle("small_text");
    auto big_text_style = display->AddStyle("big_text");
    auto arc_style = display->AddStyle("arc");
    auto bar_style = display->AddStyle("bar");
    
    display->Create();

    small_text_style->setTextColor(lv_color_make(128, 128, 128));
    small_text_style->setLineColor(lv_color_make(128, 128, 128));

    big_text_style->setTextColor(lv_color_make(60, 30, 60));

    arc_style->setArcColor(lv_color_make(210, 210, 210));

    bar_style->setBgColor(lv_color_make(210, 210, 210));
    bar_style->setBorderWidth(1);
    bar_style->setBorderColor(lv_color_make(200, 200, 200));


    delimeter->setAlign(LV_ALIGN_CENTER, 0, 0);
    delimeter->addPoint(-300, 0);
    delimeter->addPoint(300, 0);
    delimeter->addStyle(small_text_style, 0);
    delimeter->update();


    labelPM25->setStyleTextFont(&lv_font_montserrat_10, 0);
    labelPM25->setAlign(LV_ALIGN_TOP_MID, 0, 30);
    labelPM25->addStyle(small_text_style, 0);
    labelPM25->setText("PM2.5(ug/m3)");

    labelPM25data->setStyleTextFont(&lv_font_montserrat_40, 0);
    labelPM25data->addStyle(big_text_style, 0);
    labelPM25data->setAlign(LV_ALIGN_TOP_MID, 0, 40);

    progressPM25->setSize(125, 125);
    progressPM25->setRotation(90);
    progressPM25->setBgAngles(0, 360);
    progressPM25->addStyle(arc_style, 0);
    progressPM25->clearFlag(LV_OBJ_FLAG_CLICKABLE);
    progressPM25->setAlign(LV_ALIGN_CENTER, 0, -60);


    labelTVOC->setStyleTextFont(&lv_font_montserrat_10, 0);
    labelTVOC->setAlign(LV_ALIGN_LEFT_MID, 5, 10);
    labelTVOC->addStyle(small_text_style, 0);
    labelTVOC->setText("tVOC(mg/m3)");

    labelTVOCdata->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelTVOCdata->addStyle(big_text_style, 0);
    labelTVOCdata->setAlign(LV_ALIGN_LEFT_MID, 5, 30);

    progressTVOC->setAlign(LV_ALIGN_LEFT_MID, 5, 50);
    progressTVOC->addStyle(bar_style, 0);
    progressTVOC->setWidth(150);


    labelCO2->setStyleTextFont(&lv_font_montserrat_10, 0);
    labelCO2->setAlign(LV_ALIGN_RIGHT_MID, -5, 10);
    labelCO2->addStyle(small_text_style, 0);
    labelCO2->setText("CO2(ppm)");

    labelCO2data->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelCO2data->addStyle(big_text_style, 0);
    labelCO2data->setAlign(LV_ALIGN_RIGHT_MID, -5, 30);

    progressCO2->setAlign(LV_ALIGN_RIGHT_MID, -5, 50);
    progressCO2->addStyle(bar_style, 0);
    progressCO2->setWidth(150);


    labelTemp->setStyleTextFont(&lv_font_montserrat_10, 0);
    labelTemp->setAlign(LV_ALIGN_LEFT_MID, 5, 70);
    labelTemp->addStyle(small_text_style, 0);
    labelTemp->setText("Temp(°C)");

    labelTempdata->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelTempdata->addStyle(big_text_style, 0);
    labelTempdata->setAlign(LV_ALIGN_LEFT_MID, 5, 90);

    progressTemp->setAlign(LV_ALIGN_LEFT_MID, 5, 110);
    progressTemp->addStyle(bar_style, 0);
    progressTemp->setWidth(150);


    labelHum->setStyleTextFont(&lv_font_montserrat_10, 0);
    labelHum->setAlign(LV_ALIGN_RIGHT_MID, -5, 70);
    labelHum->addStyle(small_text_style, 0);
    labelHum->setText("Hum(%)");

    labelHumdata->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelHumdata->addStyle(big_text_style, 0);
    labelHumdata->setAlign(LV_ALIGN_RIGHT_MID, -5, 90);

    progressHum->setAlign(LV_ALIGN_RIGHT_MID, -5, 110);
    progressHum->addStyle(bar_style, 0);
    progressHum->setWidth(150);

    sensor_pm25.bind(std::move([=](const uint16_t &val)
    {
        Serial.println(val);
        auto sr = std::string(String(val).c_str());
        labelPM25data->setText(sr);
        progressPM25->setValue(val/2300.0 * 100);
    }));

    SensorHandler::GetInstance()->AddSensor<SensorPMS5003>("pms5003");
    SensorHandler::GetInstance()->GetLast()->AttachErrorCB(std::move([&](const std::string& error) { ErrorHandler(error); }));
    /*SensorHandler::GetInstance()->AddSensor<SensorMHZ19>("MH-Z19");
    SensorHandler::GetInstance()->AddSensor<SensorSGP40>("SGP40");
    SensorHandler::GetInstance()->AddSensor<SensorSHT31>("SHT31");*/
    
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