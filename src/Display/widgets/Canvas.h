#pragma once
#include "BaseControl.h"

class CCanvas : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setBuffer(void * buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf);
    void setPxColor(lv_coord_t x, lv_coord_t y, lv_color_t c);
    void setPxOpa(lv_coord_t x, lv_coord_t y, lv_opa_t opa);
    void setPallete(uint8_t id, lv_color_t c);
    lv_color_t getPx(lv_coord_t x, lv_coord_t y);
    lv_img_dsc_t* getImage();
    void copyBuffer(const void * to_copy, lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h);
    void transform(lv_img_dsc_t* img, int16_t angle, uint16_t zoom, lv_coord_t offset_x, lv_coord_t offset_y, int32_t pivot_x, int32_t pivot_y, bool antialias);
    void blurHorisontal(const lv_area_t * area, uint16_t r);
    void blurVertical(const lv_area_t * area, uint16_t r);
    void fillBg(lv_color_t color, lv_opa_t opa);
    void drawRect(lv_coord_t x, lv_coord_t y, lv_coord_t w, lv_coord_t h, const lv_draw_rect_dsc_t * draw_dsc);
    void drawText(lv_coord_t x, lv_coord_t y, lv_coord_t max_w, lv_draw_label_dsc_t * draw_dsc, const char* txt);
    void drawImage(lv_coord_t x, lv_coord_t y, const void * src, const lv_draw_img_dsc_t * draw_dsc);
    void drawLine(const lv_point_t points[], uint32_t point_cnt, const lv_draw_line_dsc_t * draw_dsc);
    void drawPolygon(const lv_point_t points[], uint32_t point_cnt, const lv_draw_rect_dsc_t * draw_dsc);
    void drawArc(lv_coord_t x, lv_coord_t y, lv_coord_t r, int32_t start_angle, int32_t end_angle, const lv_draw_arc_dsc_t * draw_dsc);
};