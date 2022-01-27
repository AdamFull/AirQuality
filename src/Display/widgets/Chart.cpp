#include "Chart.h"

void CChart::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_chart_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CChart::setType(lv_chart_type_t type)
{
    lv_chart_set_type(m_pInstance.get(), type);
}

void CChart::setPointCount(uint16_t cnt)
{
    lv_chart_set_point_count(m_pInstance.get(), cnt);
}

void CChart::setRange(lv_chart_axis_t axis, lv_coord_t min, lv_coord_t max)
{
    lv_chart_set_range(m_pInstance.get(), axis, min, max);
}

void CChart::setUpdateMode(lv_chart_update_mode_t update_mode)
{
    lv_chart_set_update_mode(m_pInstance.get(), update_mode);
}

void CChart::setDivLineCount(uint8_t hdiv, uint8_t vdiv)
{
    lv_chart_set_div_line_count(m_pInstance.get(), hdiv, vdiv);
}

void CChart::setZoomX(uint16_t zoom_x)
{
    lv_chart_set_zoom_x(m_pInstance.get(), zoom_x);
}

void CChart::setZoomY(uint16_t zoom_y)
{
    lv_chart_set_zoom_y(m_pInstance.get(), zoom_y);
}

uint16_t CChart::getZoomX()
{
    return lv_chart_get_zoom_x(m_pInstance.get());
}

uint16_t CChart::getZoomY()
{
    return lv_chart_get_zoom_y(m_pInstance.get());
}

void CChart::setAxisTick(lv_chart_axis_t axis, lv_coord_t major_len, lv_coord_t minor_len, lv_coord_t major_cnt, lv_coord_t minor_cnt, bool label_en, lv_coord_t draw_size)
{
    lv_chart_set_axis_tick(m_pInstance.get(), axis, major_len, minor_len, major_cnt, minor_cnt, label_en, draw_size);
}

lv_chart_type_t CChart::getType()
{
    return lv_chart_get_type(m_pInstance.get());
}

uint16_t CChart::getPointCount()
{
    return lv_chart_get_point_count(m_pInstance.get());
}

uint16_t CChart::getXStartPoint(lv_chart_series_t* ser)
{
    return lv_chart_get_x_start_point(m_pInstance.get(), ser);
}

void CChart::getPointPosById(lv_chart_series_t* ser, uint16_t id, lv_point_t* p_out)
{
    lv_chart_get_point_pos_by_id(m_pInstance.get(), ser, id, p_out);
}   

void CChart::refresh()
{
    lv_chart_refresh(m_pInstance.get());
}

lv_chart_series_t* CChart::addSeries(lv_color_t color, lv_chart_axis_t axis)
{
    return lv_chart_add_series(m_pInstance.get(), color, axis);
}

void CChart::removeSeries(lv_chart_series_t* series)
{
    lv_chart_remove_series(m_pInstance.get(), series);
}

void CChart::hideSeries(lv_chart_series_t* series, bool hide)
{
    lv_chart_hide_series(m_pInstance.get(), series, hide);
}

void CChart::setSeriesColor(lv_chart_series_t* series, lv_color_t color)
{
    lv_chart_set_series_color(m_pInstance.get(), series, color);
}

void CChart::setXStartPoint(lv_chart_series_t* ser, uint16_t id)
{
    lv_chart_set_x_start_point(m_pInstance.get(), ser, id);
}

lv_chart_series_t* CChart::getSeriesNext(const lv_chart_series_t* ser)
{
    return lv_chart_get_series_next(m_pInstance.get(), ser);
}

lv_chart_cursor_t* CChart::addCursor(lv_color_t color, lv_dir_t dir)
{
    return lv_chart_add_cursor(m_pInstance.get(), color, dir);
}

void CChart::setCursorPos(lv_chart_cursor_t* cursor, lv_point_t* pos)
{
    lv_chart_set_cursor_pos(m_pInstance.get(), cursor, pos);
}

void CChart::setCursorPoint(lv_chart_cursor_t* cursor, lv_chart_series_t* ser, uint16_t point_id)
{
    lv_chart_set_cursor_point(m_pInstance.get(), cursor, ser, point_id);
}

lv_point_t CChart::getCursorPoint(lv_chart_cursor_t* cursor)
{
    return lv_chart_get_cursor_point(m_pInstance.get(), cursor);
}

void CChart::setAllValue(lv_chart_series_t* ser, lv_coord_t value)
{
    lv_chart_set_all_value(m_pInstance.get(), ser, value);
}

void CChart::setNextValue(lv_chart_series_t* ser, lv_coord_t value)
{
    lv_chart_set_next_value(m_pInstance.get(), ser, value);
}

void CChart::setNextValue2(lv_chart_series_t* ser, lv_coord_t x_value, lv_coord_t y_value)
{
    lv_chart_set_next_value2(m_pInstance.get(), ser, x_value, y_value);
}

void CChart::setValueById(lv_chart_series_t* ser, uint16_t id, lv_coord_t value)
{
    lv_chart_set_value_by_id(m_pInstance.get(), ser, id, value);
}

void CChart::setValueById2(lv_chart_series_t* ser, uint16_t id, lv_coord_t x_value, lv_coord_t y_value)
{
    lv_chart_set_value_by_id2(m_pInstance.get(), ser, id, x_value, y_value);
}

void CChart::setExtYArray(lv_chart_series_t* ser, lv_coord_t array[])
{
    lv_chart_set_ext_y_array(m_pInstance.get(), ser, array);
}

void CChart::setExtXArray(lv_chart_series_t* ser, lv_coord_t array[])
{   
    lv_chart_set_ext_x_array(m_pInstance.get(), ser, array);
}

lv_coord_t* CChart::getYArray(lv_chart_series_t* ser)
{
    return lv_chart_get_y_array(m_pInstance.get(), ser);
}

lv_coord_t* CChart::getXArray(lv_chart_series_t* ser)
{
    return lv_chart_get_x_array(m_pInstance.get(), ser);
}

uint32_t CChart::getPressedPoint()
{
    return lv_chart_get_pressed_point(m_pInstance.get());
}
