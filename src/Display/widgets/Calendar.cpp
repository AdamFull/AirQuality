#include "Calendar.h"

void CCalendar::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_calendar_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CCalendar::setTodayDate(uint32_t year, uint32_t month, uint32_t day)
{
    lv_calendar_set_today_date(m_pInstance.get(), year, month, day);
}

void CCalendar::setShowedDate(uint32_t year, uint32_t month)
{
    lv_calendar_set_showed_date(m_pInstance.get(), year, month);
}

void CCalendar::setHighlitedDates(const std::vector<lv_calendar_date_t>& dates)
{
    lv_calendar_set_highlighted_dates(m_pInstance.get(), (lv_calendar_date_t*)dates.data(), dates.size());
}

void CCalendar::setDayNames(const std::vector<const char*>& day_names)
{
    lv_calendar_set_day_names(m_pInstance.get(), (const char**)day_names.data());
}

lv_obj_t* CCalendar::getButtonMatrix()
{
    return lv_calendar_get_btnmatrix(m_pInstance.get());
}

const lv_calendar_date_t* CCalendar::getTodayDate()
{
    return lv_calendar_get_today_date(m_pInstance.get());
}

const lv_calendar_date_t* CCalendar::getShowedDate()
{
    return lv_calendar_get_showed_date(m_pInstance.get());
}

const std::vector<lv_calendar_date_t> CCalendar::getHighlitedDates()
{
    auto res = lv_calendar_get_highlighted_dates(m_pInstance.get());
    auto size = getHighlitedDaysNum();
    return std::vector<lv_calendar_date_t>(res, res + size);
}

uint16_t CCalendar::getHighlitedDaysNum()
{
    return lv_calendar_get_highlighted_dates_num(m_pInstance.get());
}

lv_res_t CCalendar::getPressedDate(lv_calendar_date_t* date)
{
    return lv_calendar_get_pressed_date(m_pInstance.get(), date);
}
