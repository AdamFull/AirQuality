#include "StyleHandle.h"

void CStyle::create()
{
    lv_style_init(&m_pStyle);
}

void CStyle::reset()
{
    lv_style_reset(&m_pStyle);
}

void CStyle::removeProp(lv_style_prop_t prop)
{
    lv_style_remove_prop(&m_pStyle, prop);
}

void CStyle::setProp(lv_style_prop_t prop, lv_style_value_t value)
{
    lv_style_set_prop(&m_pStyle, prop, value);
}

std::pair<lv_res_t, lv_style_value_t> CStyle::getProp(lv_style_prop_t prop)
{
    lv_style_value_t val;
    auto res = lv_style_get_prop(&m_pStyle, prop, &val);
    return std::make_pair(res, val);
}

bool CStyle::isEmpty()
{
    return lv_style_is_empty(&m_pStyle);
}

lv_style_t* CStyle::get()
{
    return &m_pStyle;
}

void CStyle::setWidth(lv_coord_t value)
{
    lv_style_set_width(&m_pStyle, value);
}

void CStyle::setMinWidth(lv_coord_t value)
{
    lv_style_set_min_width(&m_pStyle, value);
}

void CStyle::setMaxWidth(lv_coord_t value)
{
    lv_style_set_max_width(&m_pStyle, value);
}

void CStyle::setHeight(lv_coord_t value)
{
    lv_style_set_height(&m_pStyle, value);
}

void CStyle::setMinHeight(lv_coord_t value)
{
    lv_style_set_min_height(&m_pStyle, value);
}

void CStyle::setMaxHeight(lv_coord_t value)
{
    lv_style_set_max_height(&m_pStyle, value);
}

void CStyle::setX(lv_coord_t value)
{
    lv_style_set_x(&m_pStyle, value);
}

void CStyle::setY(lv_coord_t value)
{
    lv_style_set_y(&m_pStyle, value);
}

void CStyle::setAlign(lv_coord_t value)
{
    lv_style_set_align(&m_pStyle, value);
}

void CStyle::setTransformWidth(lv_coord_t value)
{
    lv_style_set_transform_width(&m_pStyle, value);
}

void CStyle::setTransformHeight(lv_coord_t value)
{
    lv_style_set_transform_height(&m_pStyle, value);
}

void CStyle::setTranslateX(lv_coord_t value)
{
    lv_style_set_translate_x(&m_pStyle, value);
}

void CStyle::setTranslateY(lv_coord_t value)
{
    lv_style_set_translate_y(&m_pStyle, value);
}

void CStyle::setTransformZoom(lv_coord_t value)
{
    lv_style_set_transform_zoom(&m_pStyle, value);
}

void CStyle::setTransformAngle(lv_coord_t value)
{
    lv_style_set_transform_angle(&m_pStyle, value);
}

void CStyle::setPadTop(lv_coord_t value)
{
    lv_style_set_pad_top(&m_pStyle, value);
}

void CStyle::setPadBottom(lv_coord_t value)
{
    lv_style_set_pad_bottom(&m_pStyle, value);
}

void CStyle::setPadLeft(lv_coord_t value)
{
    lv_style_set_pad_left(&m_pStyle, value);
}

void CStyle::setPadRight(lv_coord_t value)
{
    lv_style_set_pad_right(&m_pStyle, value);
}

void CStyle::setPadRow(lv_coord_t value)
{
    lv_style_set_pad_row(&m_pStyle, value);
}

void CStyle::setPadColumt(lv_coord_t value)
{
    lv_style_set_pad_column(&m_pStyle, value);
}

void CStyle::setRadius(lv_coord_t value)
{
    lv_style_set_radius(&m_pStyle, value);
}

void CStyle::setClipCorner(bool value)
{
    lv_style_set_clip_corner(&m_pStyle, value);
}

void CStyle::setOpa(lv_opa_t value)
{
    lv_style_set_opa(&m_pStyle, value);
}

void CStyle::setColorFilterDsc(const lv_color_filter_dsc_t *value)
{
    lv_style_set_color_filter_dsc(&m_pStyle, value);
}

void CStyle::setColorFilterOpa(lv_opa_t value)
{
    lv_style_set_color_filter_opa(&m_pStyle, value);
}

void CStyle::setAnimTime(uint32_t value)
{
    lv_style_set_anim_time(&m_pStyle, value);
}

void CStyle::setAnimSpeed(uint32_t value)
{
    lv_style_set_anim_speed(&m_pStyle, value);
}

void CStyle::setTransition(const lv_style_transition_dsc_t *value)
{
    lv_style_set_transition(&m_pStyle, value);
}

void CStyle::setBlendMode(lv_blend_mode_t value)
{
    lv_style_set_blend_mode(&m_pStyle, value);
}

void CStyle::setLayout(uint16_t value)
{
    lv_style_set_layout(&m_pStyle, value);
}

void CStyle::setBaseDir(lv_base_dir_t value)
{
    lv_style_set_base_dir(&m_pStyle, value);
}

void CStyle::setBgColor(lv_color_t value)
{
    lv_style_set_bg_color(&m_pStyle, value);
}

void CStyle::setBgColorFiltered(lv_color_t value)
{
    lv_style_set_bg_color_filtered(&m_pStyle, value);
}

void CStyle::setBgOpa(lv_opa_t value)
{
    lv_style_set_bg_opa(&m_pStyle, value);
}

void CStyle::setBgGradColor(lv_color_t value)
{
    lv_style_set_bg_grad_color(&m_pStyle, value);
}

void CStyle::setBgGradColorFiltered(lv_color_t value)
{
    lv_style_set_bg_grad_color_filtered(&m_pStyle, value);
}

void CStyle::setBgGradDir(lv_grad_dir_t value)
{
    lv_style_set_bg_grad_dir(&m_pStyle, value);
}

void CStyle::setBgMainStop(lv_coord_t value)
{
    lv_style_set_bg_main_stop(&m_pStyle, value);
}

void CStyle::setBgGradStop(lv_coord_t value)
{
    lv_style_set_bg_grad_stop(&m_pStyle, value);
}

void CStyle::setBgImgSrc(const void *value)
{
    lv_style_set_bg_img_src(&m_pStyle, value);
}

void CStyle::setBgImgOpa(lv_opa_t value)
{
    lv_style_set_bg_img_opa(&m_pStyle, value);
}

void CStyle::setBgImgRecolor(lv_color_t value)
{
    lv_style_set_bg_img_recolor(&m_pStyle, value);
}

void CStyle::setBgImgRecolorFiltered(lv_color_t value)
{
    lv_style_set_bg_img_recolor_filtered(&m_pStyle, value);
}

void CStyle::setBgImgRecolorOpa(lv_opa_t value)
{
    lv_style_set_bg_img_recolor_opa(&m_pStyle, value);
}

void CStyle::setBgImgTiled(bool value)
{
    lv_style_set_bg_img_tiled(&m_pStyle, value);
}

void CStyle::setBorderColor(lv_color_t value)
{
    lv_style_set_border_color(&m_pStyle, value);
}

void CStyle::setBorderColorFiltered(lv_color_t value)
{
    lv_style_set_border_color_filtered(&m_pStyle, value);
}

void CStyle::setBorderOpa(lv_opa_t value)
{
    lv_style_set_border_opa(&m_pStyle, value);
}

void CStyle::setBorderWidth(lv_coord_t value)
{
    lv_style_set_border_width(&m_pStyle, value);
}

void CStyle::setBorderSide(lv_border_side_t value)
{
    lv_style_set_border_side(&m_pStyle, value);
}

void CStyle::setBorderPost(bool value)
{
    lv_style_set_border_post(&m_pStyle, value);
}

void CStyle::setTextColor(lv_color_t value)
{
    lv_style_set_text_color(&m_pStyle, value);
}

void CStyle::setTextColorFiltered(lv_color_t value)
{
    lv_style_set_text_color_filtered(&m_pStyle, value);
}

void CStyle::setTextOpa(lv_opa_t value)
{
    lv_style_set_text_opa(&m_pStyle, value);
}

void CStyle::setTextFont(const lv_font_t *value)
{
    lv_style_set_text_font(&m_pStyle, value);
}

void CStyle::setTextLetterSpace(lv_coord_t value)
{
    lv_style_set_text_letter_space(&m_pStyle, value);
}

void CStyle::setTextLineSpace(lv_coord_t value)
{
    lv_style_set_text_line_space(&m_pStyle, value);
}

void CStyle::setTextDecor(lv_text_decor_t value)
{
    lv_style_set_text_decor(&m_pStyle, value);
}

void CStyle::setTextAlign(lv_text_decor_t value)
{
    lv_style_set_text_align(&m_pStyle, value);
}

void CStyle::setImgOpa(lv_opa_t value)
{
    lv_style_set_img_opa(&m_pStyle, value);
}

void CStyle::setImgRecolor(lv_color_t value)
{
    lv_style_set_img_recolor(&m_pStyle, value);
}

void CStyle::setImgRecolorFiltered(lv_color_t value)
{
    lv_style_set_img_recolor_filtered(&m_pStyle, value);
}

void CStyle::setImgRecolorOpa(lv_opa_t value)
{
    lv_style_set_img_recolor_opa(&m_pStyle, value);
}

void CStyle::setOutlineWidth(lv_coord_t value)
{
    lv_style_set_outline_width(&m_pStyle, value);
}

void CStyle::setShadowWidth(lv_coord_t value)
{
    lv_style_set_shadow_width(&m_pStyle, value);
}

void CStyle::setShadowOfsX(lv_coord_t value)
{
    lv_style_set_shadow_ofs_x(&m_pStyle, value);
}

void CStyle::setShadowOfsY(lv_coord_t value)
{
    lv_style_set_shadow_ofs_y(&m_pStyle, value);
}

void CStyle::setShadowSpread(lv_coord_t value)
{
    lv_style_set_shadow_spread(&m_pStyle, value);
}

void CStyle::setShadowColor(lv_color_t value)
{
    lv_style_set_shadow_color(&m_pStyle, value);
}

void CStyle::setOutlineColor(lv_color_t value)
{
    lv_style_set_outline_color(&m_pStyle, value);
}

void CStyle::setOutlineColorFiltered(lv_color_t value)
{
    lv_style_set_outline_color_filtered(&m_pStyle, value);
}

void CStyle::setOutlineOpa(lv_opa_t value)
{
    lv_style_set_outline_opa(&m_pStyle, value);
}

void CStyle::setOutlinePad(lv_coord_t value)
{
    lv_style_set_outline_pad(&m_pStyle, value);
}

void CStyle::setShadowColorFiltered(lv_color_t value)
{
    lv_style_set_shadow_color_filtered(&m_pStyle, value);
}

void CStyle::setShadowOpa(lv_opa_t value)
{
    lv_style_set_shadow_opa(&m_pStyle, value);
}

void CStyle::setLineWidth(lv_coord_t value)
{
    lv_style_set_line_width(&m_pStyle, value);
}

void CStyle::setLineDashWidth(lv_coord_t value)
{
    lv_style_set_line_dash_width(&m_pStyle, value);
}

void CStyle::setLineDashGap(lv_coord_t value)
{
    lv_style_set_line_dash_gap(&m_pStyle, value);
}

void CStyle::setLineRounded(bool value)
{
    lv_style_set_line_rounded(&m_pStyle, value);
}

void CStyle::setLineColor(lv_color_t value)
{
    lv_style_set_line_color(&m_pStyle, value);
}

void CStyle::setLineColorFiltered(lv_color_t value)
{
    lv_style_set_line_color_filtered(&m_pStyle, value);
}

void CStyle::setLineOpa(lv_opa_t value)
{
    lv_style_set_line_opa(&m_pStyle, value);
}

void CStyle::setArcWidth(lv_coord_t value)
{
    lv_style_set_arc_width(&m_pStyle, value);
}

void CStyle::setArdRounded(bool value)
{
    lv_style_set_arc_rounded(&m_pStyle, value);
}

void CStyle::setArcColor(lv_color_t value)
{
    lv_style_set_arc_color(&m_pStyle, value);
}

void CStyle::setArcColorFiltered(lv_color_t value)
{
    lv_style_set_arc_color_filtered(&m_pStyle, value);
}

void CStyle::setArcOpa(lv_opa_t value)
{
    lv_style_set_arc_opa(&m_pStyle, value);
}

void CStyle::setArcImgSrc(const void *value)
{
    lv_style_set_arc_img_src(&m_pStyle, value);
}