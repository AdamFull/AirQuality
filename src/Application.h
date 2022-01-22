#pragma once
#include "NextionHandler.hpp"
#include "NotifyProperty.hpp"

class Application
{
public:
	Application() = default;

	void Create();
	void Update();
    void ErrorHandler(const std::string& error);

private:
	std::shared_ptr<NextionHandler> display;
	notify_uint16_t sensor_pm25;
    notify_uint8_t pm25_percent;
};