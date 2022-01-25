#pragma once
#include "NotifyProperty.hpp"
#include "DisplayHandler.hpp"
#include <memory>

class Application
{
public:
	Application() = default;

	void Create();
	void Update();
    void ErrorHandler(const std::string& error);

private:
	std::unique_ptr<DisplayHandler> display;
	notify_uint16_t sensor_pm25;
    notify_uint8_t pm25_percent;
};