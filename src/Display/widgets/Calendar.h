#pragma once
#include "BaseControl.h"

class CCalendar : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setTodayDate(uint32_t year, uint32_t month, uint32_t day);
    void setShowedDate(uint32_t year, uint32_t month);
    void setHighlitedDates(const std::vector<lv_calendar_date_t>& dates);
    void setDayNames(const std::vector<const char*>& day_names);
    lv_obj_t* getButtonMatrix();
    const lv_calendar_date_t* getTodayDate();
    const lv_calendar_date_t* getShowedDate();
    const std::vector<lv_calendar_date_t> getHighlitedDates();
    uint16_t getHighlitedDaysNum();
    lv_res_t getPressedDate(lv_calendar_date_t* date);
};