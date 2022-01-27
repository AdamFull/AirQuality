#include "Canvas.h"

void CCanvas::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_canvas_create(pParent->getObj()));
    CBaseControl::create(pParent);
}

void CCanvas::setBuffer(void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
{
    lv_canvas_set_buffer(m_pInstance.get(), buf, w, h, cf);
}

void CCanvas::setPxColor(lv_coord_t x, lv_coord_t y, lv_color_t c)
{
    lv_canvas_set_px_color(m_pInstance.get(), x, y, c);
}

void CCanvas::setPxOpa(lv_coord_t x, lv_coord_t y, lv_opa_t opa)
{
    lv_canvas_set_px_opa(m_pInstance.get(), x, y, opa);
}

void CCanvas::setPallete(uint8_t id, lv_color_t c)
{   
    lv_canvas_set_palette(m_pInstance.get(), id, c);
}

lv_color_t CCanvas::getPx(lv_coord_t x, lv_coord_t y)
{
    return lv_canvas_get_px(m_pInstance.get(), x, y);
}

lv_img_dsc_t* CCanvas::getImage()
{
    return lv_canvas_get_img(m_pInstance.get());
}

void CCanvas::copyBuffer(const void * to_copy, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h)
{
    lv_canvas_copy_buf(m_pInstance.get(), to_copy, x, y, w, h);
}

void CCanvas::transform(lv_img_dsc_t* img, int16_t angle, uint16_t zoom, lv_coord_t offset_x, lv_coord_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias)
{
    lv_canvas_transform(m_pInstance.get(), img, angle, zoom, offset_x, offset_y, pivot_x, pivot_y, antialias);
}

void CCanvas::blurHorisontal(const lv_area_t * area, uint16_t r)
{
    lv_canvas_blur_hor(m_pInstance.get(), area, r);
}

void CCanvas::blurVertical(const lv_area_t * area, uint16_t r)
{
    lv_canvas_blur_ver(m_pInstance.get(), area, r);
}

void CCanvas::fillBg(lv_color_t color, lv_opa_t opa)
{
    lv_canvas_fill_bg(m_pInstance.get(), color, opa);
}

void CCanvas::drawRect(lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, const lv_draw_rect_dsc_t * draw_dsc)
{
    lv_canvas_draw_rect(m_pInstance.get(), x, y, w, h, draw_dsc);
}

void CCanvas::drawText(lv_coord_t x, lv_coord_t y, lv_coord_t max_w, lv_draw_label_dsc_t * draw_dsc, const char* txt)
{
    lv_canvas_draw_text(m_pInstance.get(), x, y, max_w, draw_dsc, txt);
}

void CCanvas::drawImage(lv_coord_t x, lv_coord_t y, const void * src, const lv_draw_img_dsc_t * draw_dsc)
{
    lv_canvas_draw_img(m_pInstance.get(), x, y, src, draw_dsc);
}

void CCanvas::drawLine(const lv_point_t points[], uint32_t point_cnt, const lv_draw_line_dsc_t * draw_dsc)
{
    lv_canvas_draw_line(m_pInstance.get(), points, point_cnt, draw_dsc);
}

void CCanvas::drawPolygon(const lv_point_t points[], uint32_t point_cnt, const lv_draw_rect_dsc_t * draw_dsc)
{
    lv_canvas_draw_polygon(m_pInstance.get(), points, point_cnt, draw_dsc);
}

void CCanvas::drawArc(lv_coord_t x, lv_coord_t y, lv_coord_t r, int32_t start_angle, int32_t end_angle, const lv_draw_arc_dsc_t * draw_dsc)
{
    lv_canvas_draw_arc(m_pInstance.get(), x, y, r, start_angle, end_angle, draw_dsc);
}
