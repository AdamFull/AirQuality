#pragma once
#include <NotifyProperty.hpp>
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

    template<class... Args>
    void AttachErrorCB(Args... args)
    {
        m_errorCallback = std::move(EasyDelegate::TDelegate<void(const std::string&)>(std::forward<Args>(args)...));
    }

    template<class T, class... Args>
    void subscribe(const std::string& vname, Args... args)
    {
        auto& val = GetValue<T>(vname);
        val.bind(std::forward<Args>(args)...);
    }
protected:
    template<class T>
    T& AddValue(const std::string& vname)
    {
        static_assert(react::is_react_value<T>::value, "Cannot add non-reactive value as sensor value.");
        m_values.emplace(vname, T());
        return std::get<T>(m_values.at(vname));
    }

    template<class T>
    T& GetValue(const std::string& vname)
    {
        return std::get<T>(m_values.at(vname));
    }
    
    EasyDelegate::TDelegate<void(const std::string&)> m_errorCallback;
    std::map<std::string, react::variants> m_values;
};