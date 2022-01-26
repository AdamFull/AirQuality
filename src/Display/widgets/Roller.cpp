#include "Roller.h"

void CRoller::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_roller_create(pParent));
    CBaseControl::create(pParent);
}

void CRoller::setOptions(const std::string& srOpt, lv_roller_mode_t mode)
{
    lv_roller_set_options(m_pInstance.get(), srOpt.c_str(), mode);
}

void CRoller::setSelected(uint16_t sel_opt, lv_anim_enable_t anim)
{
    lv_roller_set_selected(m_pInstance.get(), sel_opt, anim);
}

void CRoller::setVisibleRowCount(uint8_t row_cnt)
{
    lv_roller_set_visible_row_count(m_pInstance.get(), row_cnt);
}

uint16_t CRoller::getSelected()
{
    return lv_roller_get_selected(m_pInstance.get());
}

std::string CRoller::getSelectedStr()
{
    std::string ret;
    lv_roller_get_selected_str(m_pInstance.get(), ret.data(), ret.max_size());
    return ret;
}

std::string CRoller::getOptions()
{
    //TODO: return vector of strings. Separate by ,
    return std::string(lv_roller_get_options(m_pInstance.get()));
}

uint16_t CRoller::getOptionCount()
{
    return lv_roller_get_option_cnt(m_pInstance.get());
}
 