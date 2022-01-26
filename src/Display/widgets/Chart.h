#pragma once
#include "BaseControl.h"

class CChart : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;

    void setType(lv_chart_type_t type);
    void setPointCount(uint16_t cnt);
    void setRange(lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max);
    void setUpdateMode(lv_chart_update_mode_t update_mode);
    void setDivLineCount(uint8_t hdiv, uint8_t vdiv);
    void setZoomX(uint16_t zoom_x);
    void setZoomY(uint16_t zoom_y);
    uint16_t getZoomX();
    uint16_t getZoomY();
    void setAxisTick(lv_chart_axis_t axis, lv_coord_t major_len, lv_coord_t minor_len, lv_coord_t major_cnt, lv_coord_t minor_cnt, bool label_en, lv_coord_t draw_size);
    lv_chart_type_t getType();
    uint16_t getPointCount();
    uint16_t getXStartPoint(lv_chart_series_t* ser);
    void getPointPosById(lv_chart_series_t* ser, uint16_t id, lv_point_t* p_out);
    void refresh();
    lv_chart_series_t* addSeries(lv_color_t color, lv_chart_axis_t axis);
    void removeSeries(lv_chart_series_t* series);
    void hideSeries(lv_chart_series_t* series, bool hide);
    void setSeriesColor(lv_chart_series_t* series, lv_color_t color);
    void setXStartPoint(lv_chart_series_t* ser, uint16_t id);
    lv_chart_series_t* getSeriesNext(const lv_chart_series_t* ser);
    lv_chart_cursor_t* addCursor(lv_color_t color, lv_dir_t dir);
    void setCursorPos(lv_chart_cursor_t* cursor, lv_point_t* pos);
    void setCursorPoint(lv_chart_cursor_t* cursor, lv_chart_series_t* ser, uint16_t point_id);
    lv_point_t getCursorPoint(lv_chart_cursor_t* cursor);
    void setAllValue(lv_chart_series_t* ser, lv_coord_t value);
    void setNextValue(lv_chart_series_t* ser, lv_coord_t value);
    void setNextValue2(lv_chart_series_t* ser, lv_coord_t x_value, lv_coord_t y_value);
    void setValueById(lv_chart_series_t* ser, uint16_t id, lv_coord_t value);
    void setValueById2(lv_chart_series_t* ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value);
    void setExtYArray(lv_chart_series_t* ser, lv_coord_t array[]);
    void setExtXArray(lv_chart_series_t* ser, lv_coord_t array[]);
    lv_coord_t* getYArray(lv_chart_series_t* ser);
    lv_coord_t* getXArray(lv_chart_series_t* ser);
    uint32_t getPressedPoint();
};