/*#pragma once
#include <Arduino.h>
#include <Nextion.h>
#include <SoftwareSerial.h>
#include <map>
#include <string>
#include <iostream>
#include <any>
#include <memory>

constexpr uint32_t HMI_RX = D7;
constexpr uint32_t HMI_TX = D8;

#define DEBUG

class NextionHandler
{
public:
    NextionHandler() = default;
    ~NextionHandler();

    bool Create(uint32_t bauds);

    template<class T>
    void AddControl(uint32_t pid, uint32_t id, const std::string& ctrl_name)
    {
        #ifdef DEBUG
        Serial.println(ctrl_name.c_str());
        #endif
        m_ctrls.emplace(ctrl_name, new T(m_pDisplay, pid, id, ctrl_name.c_str()));
    }

    template<class T>
    T* GetControl(const std::string& ctrl_name)
    {
        return static_cast<T*>(m_ctrls[ctrl_name]);
    }
private:
    std::map<std::string, void*> m_ctrls;
    Nextion* m_pDisplay{nullptr};
    std::unique_ptr<SoftwareSerial> HMISerial;
};*/