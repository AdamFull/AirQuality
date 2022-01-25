/*#include "NextionHandler.hpp"

NextionHandler::~NextionHandler()
{
    for(auto& [key, val] : m_ctrls)
    {
        delete val;
    }
    m_ctrls.clear();
}

bool NextionHandler::Create(uint32_t bauds)
{
    HMISerial = std::make_unique<SoftwareSerial>(HMI_RX, HMI_TX);
    HMISerial->begin(bauds);
    m_pDisplay = Nextion::GetInstance(*HMISerial.get());

    return m_pDisplay && m_pDisplay->nexInit(bauds);
}*/

#include "DisplayHandler.hpp"
#include <Arduino.h>
#include <../examples/lv_examples.h>

//constexpr auto TFT_CS = PB9, TFT_DC = PB7, TFT_RST = PB6, TFT_MOSI = PB5, TFT_MISO = PB4, TFT_CLK = PB4;

std::unique_ptr<TFT_eSPI> DisplayHandler::display;

void DisplayHandler::Create()
{
    lv_init();

    display = std::make_unique<TFT_eSPI>(screenWidth, screenHeight);
    display->init();
    display->initDMA();
    display->setRotation( 3 );

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = DisplayHandler::Flush;
    disp_drv.draw_buf = &draw_buf;
    disp_drv.antialiasing = 1;
    lv_disp_drv_register( &disp_drv );
    
    for(auto it = m_ctrls.begin(); it != m_ctrls.end(); ++it)
    {
        it->second->create(lv_scr_act());
    }
}

void DisplayHandler::Update()
{
    old_time = current_time;
    current_time = millis();
    auto delta_time = current_time - old_time;
    lv_tick_inc(delta_time);
    lv_task_handler();
    lv_timer_handler();
}

void DisplayHandler::Flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    display->startWrite();
    display->setAddrWindow( area->x1, area->y1, w, h );
    display->pushColors( ( uint16_t * )&color_p->full, w * h, true );
    display->endWrite();

    lv_disp_flush_ready( disp );
}