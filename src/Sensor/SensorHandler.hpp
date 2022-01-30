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
        auto sensor = std::make_shared<T>();
        m_sensors.emplace(sname, sensor);
        return sensor;
    }

    template<class T>
    std::shared_ptr<T> GetSensorCast(const std::string& sname)
    {
        return std::static_pointer_cast<T>(m_sensors[sname]);
    }

    std::shared_ptr<Sensor> GetSensor(const std::string& sname)
    {
        return m_sensors[sname];
    }

    inline std::shared_ptr<Sensor> GetLast()
    {
        return (--m_sensors.end())->second;
    }
private:
    std::map<std::string, std::shared_ptr<Sensor>> m_sensors;
};