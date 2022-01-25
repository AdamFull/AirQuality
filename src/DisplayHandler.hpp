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

#pragma once
#include <map>
#include <string>
#include <memory>
#include <SPI.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "Display/Controls.h"

static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

class DisplayHandler
{
public:
    void Create();
    void Update();

    template<class T>
    T* AddControl(const std::string& ctrl_name)
    {
        auto ptr = new T();
        m_ctrls.emplace(ctrl_name, ptr);
        return ptr;
    }

    template<class T>
    T* GetControl(const std::string& ctrl_name)
    {
        return static_cast<T*>(m_ctrls[ctrl_name]);
    }

    static void Flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
private:
    static std::unique_ptr<TFT_eSPI> display;
    std::map<std::string, CBaseControl*> m_ctrls;

    unsigned long current_time{0}, old_time{0};
    lv_disp_draw_buf_t draw_buf;
    lv_color_t buf[ screenWidth * 10 ];
};
