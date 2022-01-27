#include "Led.h"

void CLed::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_led_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CLed::setColor(lv_color_t color)
{
    lv_led_set_color(m_pInstance.get(), color);
}

void CLed::setBrightness(uint8_t bright)
{
    lv_led_set_brightness(m_pInstance.get(), bright);
}

void CLed::on()
{
    lv_led_on(m_pInstance.get());
}

void CLed::off()
{
    lv_led_off(m_pInstance.get());
}

void CLed::toggle()
{
    lv_led_toggle(m_pInstance.get());
}

uint8_t CLed::getBrightness()
{
    return lv_led_get_brightness(m_pInstance.get());
}
