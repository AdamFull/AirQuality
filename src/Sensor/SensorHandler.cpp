#include "SensorHandler.hpp"
#include <Wire.h>

std::unique_ptr<SensorHandler> SensorHandler::m_pInstance{nullptr};

std::unique_ptr<SensorHandler>& SensorHandler::GetInstance()
{
    if(!m_pInstance)
    {
        m_pInstance.reset(new SensorHandler);
    }
    return m_pInstance;
}

void SensorHandler::Create()
{
    Wire.begin();
    Wire.setClock(1000000);

    for(auto& [key, val] : m_sensors)
        val->Create();
}

void SensorHandler::Update()
{
    for(auto& [key, val] : m_sensors)
        val->Update();
}
