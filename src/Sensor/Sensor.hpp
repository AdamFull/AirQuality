#pragma once
#include <functional>
#include <string>
#include <any>
#include <map>

class Sensor
{
public:
    Sensor() = default;
    virtual ~Sensor() 
    {
        if(m_errorCallback)
            m_errorCallback = nullptr;
    }

    virtual void Create() {}
    virtual void Update() {}

    template<class Lambda>
    void AttachErrorCB(Lambda&& callback)
    {
        m_errorCallback = std::function<void(const std::string&)>(std::forward<Lambda>(callback));
    }

    template<class T>
    T GetValue(const std::string& vname)
    {
        return (*static_cast<T*>(m_values[vname]));
    }
protected:
    std::function<void(const std::string&)> m_errorCallback;
    std::map<std::string, void*> m_values;
};