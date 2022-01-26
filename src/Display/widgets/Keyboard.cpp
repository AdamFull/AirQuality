#include "Keyboard.h"

void CKeyboard::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_keyboard_create(pParent));
    CBaseControl::create(pParent);
}

void CKeyboard::setTextarea(lv_obj_t* pTextarea)
{
    lv_keyboard_set_textarea(m_pInstance.get(), pTextarea);
}

void CKeyboard::setMode(lv_keyboard_mode_t mode)
{
    lv_keyboard_set_mode(m_pInstance.get(), mode);
}

void CKeyboard::setPopovers(bool en)
{
    lv_keyboard_set_popovers(m_pInstance.get(), en);
}

void CKeyboard::setMap(lv_keyboard_mode_t mode, const char * map[], const lv_btnmatrix_ctrl_t ctrl_map[])
{
    lv_keyboard_set_map(m_pInstance.get(), mode, map, ctrl_map);
}

lv_obj_t* CKeyboard::getTextarea()
{
    return lv_keyboard_get_textarea(m_pInstance.get());
}

lv_keyboard_mode_t CKeyboard::getMode()
{
    return lv_keyboard_get_mode(m_pInstance.get());
}

bool CKeyboard::getPopovers()
{
    lv_btnmatrix_get_popovers(m_pInstance.get());
}

void CKeyboard::defEventCallback(lv_event_t* e)
{
    lv_keyboard_def_event_cb(e);
}
