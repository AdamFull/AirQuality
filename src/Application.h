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
	void onCreate(std::shared_ptr<CBaseControl> base);
	std::unique_ptr<DisplayHandler> display;
};