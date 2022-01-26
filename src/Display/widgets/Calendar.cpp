#include "Calendar.h"

void CCalendar::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_calendar_create(pParent));
    CBaseControl::create(pParent);
}

/*lv_calendar_set_day_names lv_calendar_set_today_date lv_calendar_set_highlighted_dates lv_calendar_set_showed_date
lv_calendar_get_btnmatrix lv_calendar_get_today_date lv_calendar_get_showed_date lv_calendar_get_highlighted_dates
lv_calendar_get_highlighted_dates_num lv_calendar_get_pressed_date*/