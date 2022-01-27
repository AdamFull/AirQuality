#pragma once
#include "BaseControl.h"

class CTabView : public CBaseControl
{
public:
    CTabView(lv_dir_t tab_pos, lv_coord_t tab_size);
    void create(std::shared_ptr<CBaseControl> pParent) override;

    lv_obj_t* addTab(const std::string& name);
    void setAct(uint32_t id, lv_anim_enable_t anim_en);
    uint16_t getTabAct();
    lv_obj_t* getContent();
    lv_obj_t* getTabButtons();

private:
    lv_dir_t m_tabPos{LV_DIR_TOP};
    lv_coord_t m_tabSize{50};
};