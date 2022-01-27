#include "Dropdown.h"

void CDropdown::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_dropdown_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CDropdown::setText(const std::string& srText)
{
    lv_dropdown_set_text(m_pInstance.get(), srText.c_str());
}

void CDropdown::setOptions(const std::string& srText)
{
    lv_dropdown_set_options(m_pInstance.get(), srText.c_str());
}

void CDropdown::setOptionsStatic(const std::string& srText)
{
    lv_dropdown_set_options_static(m_pInstance.get(), srText.c_str());
}

void CDropdown::addOption(const std::string& srText, uint32_t pos)
{
    lv_dropdown_add_option(m_pInstance.get(), srText.c_str(), pos);
}

void CDropdown::clearOptions()
{
    lv_dropdown_clear_options(m_pInstance.get());
}

void CDropdown::setSelected(uint16_t sel_opt)
{
    lv_dropdown_set_selected(m_pInstance.get(), sel_opt);
}

void CDropdown::setDir(lv_dir_t dir)
{
    lv_dropdown_set_dir(m_pInstance.get(), dir);
}

/*void setSymbol()
{
    lv_dropdown_set_symbol
}*/

void CDropdown::setSelectedHighlight(bool en)
{
    lv_dropdown_set_selected_highlight(m_pInstance.get(), en);
}