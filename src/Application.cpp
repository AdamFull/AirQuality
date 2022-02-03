#include "Application.h"
#include "Sensor/SensorHandler.hpp"
#include "Sensor/SensorPMS5003.h"
#include "Sensor/SensorMHZ19.h"
#include "Sensor/SensorSGP40.h"
#include "Sensor/SensorSHT31.h"

void Application::Create()
{
    display = std::make_unique<DisplayHandler>();
    display->setOnCreateCallback(this, &Application::onCreate);
    
    display->Create();
    
    SensorHandler::GetInstance()->Create();
}

void Application::Update()
{
    display->Update();
    SensorHandler::GetInstance()->Update();
    //sensor_pm25 = SensorHandler::GetInstance()->GetSensor("pms5003")->GetValue<react::ruint16_t>("pm25");
}

void Application::ErrorHandler(const std::string& error)
{
    Serial.println(error.c_str());
}

void Application::onCreate(std::shared_ptr<CBaseControl> base)
{
    auto delimeter = display->AddControl<CLine>("delimeter", base);

    auto labelPM25 = display->AddControl<CLabel>("labelPM25", base);
    auto labelPM25data = display->AddControl<CLabel>("labelPM25data", base);
    auto progressPM25 = display->AddControl<CCircularProgressBar>("progressPM25", base);
    
    auto labelTVOC = display->AddControl<CLabel>("labelTVOC", base);
    auto labelTVOCdata = display->AddControl<CLabel>("labelTVOCdata", base);
    auto progressTVOC = display->AddControl<CProgressBar>("progressTVOC", base);

    auto labelCO2 = display->AddControl<CLabel>("labelCO2", base);
    auto labelCO2data = display->AddControl<CLabel>("labelCO2data", base);
    auto progressCO2 = display->AddControl<CProgressBar>("progressCO2", base);

    auto labelTemp = display->AddControl<CLabel>("labelTemp", base);
    auto labelTempdata = display->AddControl<CLabel>("labelTempdata", base);
    auto progressTemp = display->AddControl<CProgressBar>("progressTemp", base);

    auto labelHum = display->AddControl<CLabel>("labelHum", base);
    auto labelHumdata = display->AddControl<CLabel>("labelHumdata", base);
    auto progressHum = display->AddControl<CProgressBar>("progressHum", base);


    auto small_text_style = display->AddStyle("small_text");
    auto big_text_style = display->AddStyle("big_text");

    auto arc_style = display->AddStyle("arc_good");

    auto bar_style = display->AddStyle("bar");

    small_text_style->setTextColor(lv_color_make(128, 128, 128));
    small_text_style->setLineColor(lv_color_make(128, 128, 128));

    big_text_style->setTextColor(lv_color_make(60, 30, 60));

    arc_style->setArcColor(lv_color_make(0,255,0));

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
    progressPM25->addStyle(arc_style, LV_PART_INDICATOR);
    progressPM25->setAlign(LV_ALIGN_CENTER, 0, -60);
    progressPM25->setRange(0, 2300);


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
    progressTVOC->setRange(0, 2300);


    labelCO2->setStyleTextFont(&lv_font_montserrat_10, 0);
    labelCO2->setAlign(LV_ALIGN_RIGHT_MID, -5, 10);
    labelCO2->addStyle(small_text_style, 0);
    labelCO2->setText("CO2(ppm)");

    labelCO2data->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelCO2data->addStyle(big_text_style, 0);
    labelCO2data->setAlign(LV_ALIGN_RIGHT_MID, -5, 30);

    progressCO2->setAlign(LV_ALIGN_RIGHT_MID, -5, 50);
    progressCO2->addStyle(bar_style, 0);
    progressCO2->setStyleBaseDir(LV_BASE_DIR_RTL, 0);
    progressCO2->setWidth(150);
    progressCO2->setRange(0, 2300);


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
    progressTemp->setRange(0, 2300);


    labelHum->setStyleTextFont(&lv_font_montserrat_10, 0);
    labelHum->setAlign(LV_ALIGN_RIGHT_MID, -5, 70);
    labelHum->addStyle(small_text_style, 0);
    labelHum->setText("Hum(%)");

    labelHumdata->setStyleTextFont(&lv_font_montserrat_30, 0);
    labelHumdata->addStyle(big_text_style, 0);
    labelHumdata->setAlign(LV_ALIGN_RIGHT_MID, -5, 90);
    
    progressHum->setAlign(LV_ALIGN_RIGHT_MID, -5, 110);
    progressHum->addStyle(bar_style, 0);
    progressHum->setStyleBaseDir(LV_BASE_DIR_RTL, 0);
    progressHum->setWidth(150);
    progressHum->setRange(0, 2300);


    /* Subscribtion to sensors */
    auto pms5003 = SensorHandler::GetInstance()->AddSensor<SensorPMS5003>("pms5003");
    pms5003->AttachErrorCB(std::move([&](const std::string& error) { ErrorHandler(error); }));
    pms5003->subscribe<react::ruint16_t>(SensorPMS5003::VAL_PM25, [=](const uint16_t &old, const uint16_t &val)
    {
        labelPM25data->setValueRanged(old, val);
        progressPM25->setValueRanged(old, val);
        auto progress = (val / 2300.0) * 100;
        if(progress < 35)
            arc_style->setArcColor(lv_color_make(0,255,0));
        else if(progress > 30 && progress < 70)
            arc_style->setArcColor(lv_color_make(255,255,0));
        else
            arc_style->setArcColor(lv_color_make(255,0,0));
//VECT_TAB_ADDR;
        progressPM25->refreshStyle(LV_PART_INDICATOR, LV_STYLE_ARC_COLOR);

        Serial.printf("%d:%d\n", old, val);
    });
    /*SensorHandler::GetInstance()->AddSensor<SensorMHZ19>("MH-Z19");
    SensorHandler::GetInstance()->AddSensor<SensorSGP40>("SGP40");
    SensorHandler::GetInstance()->AddSensor<SensorSHT31>("SHT31");*/
}   