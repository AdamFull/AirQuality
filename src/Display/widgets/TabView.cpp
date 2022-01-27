#include "TabView.h"

CTabView::CTabView(lv_dir_t tab_pos, lv_coord_t tab_size) : 
    m_tabPos(tab_pos), m_tabSize(tab_size)
{

}

void CTabView::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_tabview_create(pParent->getObj(), m_tabPos, m_tabSize));
    CBaseControl::create(pParent);
}

lv_obj_t* CTabView::addTab(const std::string& name)
{
    return lv_tabview_add_tab(m_pInstance.get(), name.c_str());
}

void CTabView::setAct(uint32_t id, lv_anim_enable_t anim_en)
{
    lv_tabview_set_act(m_pInstance.get(), id, anim_en);
}

uint16_t CTabView::getTabAct()
{
    return lv_tabview_get_tab_act(m_pInstance.get());
}

lv_obj_t* CTabView::getContent()
{
    return lv_tabview_get_content(m_pInstance.get());
}

lv_obj_t* CTabView::getTabButtons()
{
    return lv_tabview_get_tab_btns(m_pInstance.get());
}
