#include "DisplayHandler.hpp"
#include <Arduino.h>

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

    auto main_page = AddControl<CBaseControl>("lvgl_main_page", lv_scr_act());
    
    if(m_pOnCreateCallback)
    {
        m_pOnCreateCallback(main_page);
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

std::shared_ptr<CStyle> DisplayHandler::AddStyle(const std::string& style_name)
{
    auto ptr = std::make_shared<CStyle>();
    ptr->create();
    m_styles.emplace(style_name, ptr);
    return ptr;
}

std::shared_ptr<CStyle> DisplayHandler::GetStyle(const std::string& style_name)
{
    return m_styles[style_name];
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