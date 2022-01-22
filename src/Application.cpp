#include "Application.h"
#include "Sensor/SensorHandler.hpp"
#include "Sensor/SensorPMS5003.h"
#include "Sensor/SensorMHZ19.h"
#include "Sensor/SensorSGP40.h"
#include "Sensor/SensorSHT31.h"

void Application::Create()
{
    display = std::make_shared<NextionHandler>();

    if (!display->Create(4800))
    {
        Serial.println("Error to initialize NEXTION display.");
    }

    display->AddControl<NexText>(0, 2, "labelPM25data");
    display->AddControl<NexText>(0, 5, "labelTVOCdata");
    display->AddControl<NexText>(0, 8, "labelCO2data");
    display->AddControl<NexText>(0, 11, "labelTempdata");
    display->AddControl<NexText>(0, 14, "labelHumdata");

    display->AddControl<NexProgressBar>(0, 16, "progressPM25");
    display->AddControl<NexProgressBar>(0, 17, "progressTVOC");
    display->AddControl<NexProgressBar>(0, 19, "progressCO2");
    display->AddControl<NexProgressBar>(0, 18, "progressTemp");
    display->AddControl<NexProgressBar>(0, 20, "progressHum");

    sensor_pm25.bind(std::move([&](const uint16_t &val)
    {
        Serial.println(val);
		display->GetControl<NexText>("labelPM25data")->setText(String(val).c_str());
		pm25_percent = (val / 2300.f) * 100.f;
    }));

    pm25_percent.bind(std::move([&](const uint8_t &val)
    {
        auto* progress = display->GetControl<NexProgressBar>("progressPM25");
        progress->setValue(val);

        if(val > 40)
            progress->Set_font_color_pco(62884);
        else if(val > 70)
            progress->Set_font_color_pco(63650);
        else
            progress->Set_font_color_pco(1024); 
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
    SensorHandler::GetInstance()->Update();
    sensor_pm25 = SensorHandler::GetInstance()->GetSensor("pms5003")->GetValue<uint16_t>("pm25");
    delay(500);
}

void Application::ErrorHandler(const std::string& error)
{
    Serial.println(error.c_str());
}