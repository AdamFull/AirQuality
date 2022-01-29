#pragma once
#include "Sensor.hpp"
#include <memory>
#include <map>

class SensorHandler
{
protected:
    SensorHandler() = default;
    static std::unique_ptr<SensorHandler> m_pInstance;
public:
    SensorHandler(const SensorHandler&) = delete;
    SensorHandler(SensorHandler&&) = delete;
    SensorHandler& operator=(const SensorHandler&) = delete;
    SensorHandler& operator=(SensorHandler&&) = delete;

    static std::unique_ptr<SensorHandler>& GetInstance();

    void Create();
    void Update();

    template<class T>
    auto AddSensor(const std::string& sname) -> decltype(auto)
    {
        auto sensor = new T();
        m_sensors.emplace(sname, sensor);
        return sensor;
    }

    template<class T>
    T* GetSensorCast(const std::string& sname)
    {
        return static_cast<T*>(m_sensors[sname]);
    }

    Sensor* GetSensor(const std::string& sname)
    {
        return m_sensors[sname];
    }

    inline Sensor* GetLast()
    {
        return (--m_sensors.end())->second;
    }
private:
    std::map<std::string, Sensor*> m_sensors;
};