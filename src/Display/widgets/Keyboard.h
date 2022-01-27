#pragma once
#include "BaseControl.h"

class CKeyboard : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setTextarea(lv_obj_t* ta);
    void setMode(lv_keyboard_mode_t mode);
    void setPopovers(bool en);
    void setMap(lv_keyboard_mode_t mode, const char * map[], const lv_btnmatrix_ctrl_t ctrl_map[]);
    lv_obj_t* getTextarea();
    lv_keyboard_mode_t getMode();
    bool getPopovers();
    void defEventCallback(lv_event_t* e);
};