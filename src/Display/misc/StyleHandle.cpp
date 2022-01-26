#include "StyleHandle.h"

void CStyleHandle::create()
{
    lv_style_init(&m_pStyle);
}

void CStyleHandle::reset()
{
    lv_style_reset(&m_pStyle);
}

void CStyleHandle::removeProp(lv_style_prop_t prop)
{
    lv_style_remove_prop(&m_pStyle, prop);
}

void CStyleHandle::setProp(lv_style_prop_t prop, lv_style_value_t value)
{
    lv_style_set_prop(&m_pStyle, prop, value);
}

std::pair<lv_res_t, lv_style_value_t> CStyleHandle::getProp(lv_style_prop_t prop)
{
    lv_style_value_t val;
    auto res = lv_style_get_prop(&m_pStyle, prop, &val);
    return std::make_pair(res, val);
}

bool CStyleHandle::isEmpty()
{
    return lv_style_is_empty(&m_pStyle);
}

lv_style_t* CStyleHandle::get()
{
    return &m_pStyle;
}

void CStyleHandle::setWidth(lv_coord_t value)
{
    lv_style_set_width(&m_pStyle, value);
}

void CStyleHandle::setMinWidth(lv_coord_t value)
{
    lv_style_set_min_width(&m_pStyle, value);
}

void CStyleHandle::setMaxWidth(lv_coord_t value)
{
    lv_style_set_max_width(&m_pStyle, value);
}

void CStyleHandle::setHeight(lv_coord_t value)
{
    lv_style_set_height(&m_pStyle, value);
}

void CStyleHandle::setMinHeight(lv_coord_t value)
{
    lv_style_set_min_height(&m_pStyle, value);
}

void CStyleHandle::setMaxHeight(lv_coord_t value)
{
    lv_style_set_max_height(&m_pStyle, value);
}

void CStyleHandle::setX(lv_coord_t value)
{
    lv_style_set_x(&m_pStyle, value);
}

void CStyleHandle::setY(lv_coord_t value)
{
    lv_style_set_y(&m_pStyle, value);
}

void CStyleHandle::setAlign(lv_coord_t value)
{
    lv_style_set_align(&m_pStyle, value);
}

void CStyleHandle::setTransformWidth(lv_coord_t value)
{
    lv_style_set_transform_width(&m_pStyle, value);
}

void CStyleHandle::setTransformHeight(lv_coord_t value)
{
    lv_style_set_transform_height(&m_pStyle, value);
}

void CStyleHandle::setTranslateX(lv_coord_t value)
{
    lv_style_set_translate_x(&m_pStyle, value);
}

void CStyleHandle::setTranslateY(lv_coord_t value)
{
    lv_style_set_translate_y(&m_pStyle, value);
}

void CStyleHandle::setTransformZoom(lv_coord_t value)
{
    lv_style_set_transform_zoom(&m_pStyle, value);
}

void CStyleHandle::setTransformAngle(lv_coord_t value)
{
    lv_style_set_transform_angle(&m_pStyle, value);
}

void CStyleHandle::setPadTop(lv_coord_t value)
{
    lv_style_set_pad_top(&m_pStyle, value);
}

void CStyleHandle::setPadBottom(lv_coord_t value)
{
    lv_style_set_pad_bottom(&m_pStyle, value);
}

void CStyleHandle::setPadLeft(lv_coord_t value)
{
    lv_style_set_pad_left(&m_pStyle, value);
}

void CStyleHandle::setPadRight(lv_coord_t value)
{
    lv_style_set_pad_right(&m_pStyle, value);
}

void CStyleHandle::setPadRow(lv_coord_t value)
{
    lv_style_set_pad_row(&m_pStyle, value);
}

void CStyleHandle::setPadColumt(lv_coord_t value)
{
    lv_style_set_pad_column(&m_pStyle, value);
}

void CStyleHandle::setRadius(lv_coord_t value)
{
    lv_style_set_radius(&m_pStyle, value);
}

void CStyleHandle::setClipCorner(bool value)
{
    lv_style_set_clip_corner(&m_pStyle, value);
}

void CStyleHandle::setOpa(lv_opa_t value)
{
    lv_style_set_opa(&m_pStyle, value);
}

void CStyleHandle::setColorFilterDsc(const lv_color_filter_dsc_t *value)
{
    lv_style_set_color_filter_dsc(&m_pStyle, value);
}

void CStyleHandle::setColorFilterOpa(lv_opa_t value)
{
    lv_style_set_color_filter_opa(&m_pStyle, value);
}

void CStyleHandle::setAnimTime(uint32_t value)
{
    lv_style_set_anim_time(&m_pStyle, value);
}

void CStyleHandle::setAnimSpeed(uint32_t value)
{
    lv_style_set_anim_speed(&m_pStyle, value);
}

void CStyleHandle::setTransition(const lv_style_transition_dsc_t *value)
{
    lv_style_set_transition(&m_pStyle, value);
}

void CStyleHandle::setBlendMode(lv_blend_mode_t value)
{
    lv_style_set_blend_mode(&m_pStyle, value);
}

void CStyleHandle::setLayout(uint16_t value)
{
    lv_style_set_layout(&m_pStyle, value);
}

void CStyleHandle::setBaseDir(lv_base_dir_t value)
{
    lv_style_set_base_dir(&m_pStyle, value);
}

void CStyleHandle::setBgColor(lv_color_t value)
{
    lv_style_set_bg_color(&m_pStyle, value);
}

void CStyleHandle::setBgColorFiltered(lv_color_t value)
{
    lv_style_set_bg_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setBgOpa(lv_opa_t value)
{
    lv_style_set_bg_opa(&m_pStyle, value);
}

void CStyleHandle::setBgGradColor(lv_color_t value)
{
    lv_style_set_bg_grad_color(&m_pStyle, value);
}

void CStyleHandle::setBgGradColorFiltered(lv_color_t value)
{
    lv_style_set_bg_grad_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setBgGradDir(lv_grad_dir_t value)
{
    lv_style_set_bg_grad_dir(&m_pStyle, value);
}

void CStyleHandle::setBgMainStop(lv_coord_t value)
{
    lv_style_set_bg_main_stop(&m_pStyle, value);
}

void CStyleHandle::setBgGradStop(lv_coord_t value)
{
    lv_style_set_bg_grad_stop(&m_pStyle, value);
}

void CStyleHandle::setBgImgSrc(const void *value)
{
    lv_style_set_bg_img_src(&m_pStyle, value);
}

void CStyleHandle::setBgImgOpa(lv_opa_t value)
{
    lv_style_set_bg_img_opa(&m_pStyle, value);
}

void CStyleHandle::setBgImgRecolor(lv_color_t value)
{
    lv_style_set_bg_img_recolor(&m_pStyle, value);
}

void CStyleHandle::setBgImgRecolorFiltered(lv_color_t value)
{
    lv_style_set_bg_img_recolor_filtered(&m_pStyle, value);
}

void CStyleHandle::setBgImgRecolorOpa(lv_opa_t value)
{
    lv_style_set_bg_img_recolor_opa(&m_pStyle, value);
}

void CStyleHandle::setBgImgTiled(bool value)
{
    lv_style_set_bg_img_tiled(&m_pStyle, value);
}

void CStyleHandle::setBorderColor(lv_color_t value)
{
    lv_style_set_border_color(&m_pStyle, value);
}

void CStyleHandle::setBorderColorFiltered(lv_color_t value)
{
    lv_style_set_border_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setBorderOpa(lv_opa_t value)
{
    lv_style_set_border_opa(&m_pStyle, value);
}

void CStyleHandle::setBorderWidth(lv_coord_t value)
{
    lv_style_set_border_width(&m_pStyle, value);
}

void CStyleHandle::setBorderSide(lv_border_side_t value)
{
    lv_style_set_border_side(&m_pStyle, value);
}

void CStyleHandle::setBorderPost(bool value)
{
    lv_style_set_border_post(&m_pStyle, value);
}

void CStyleHandle::setTextColor(lv_color_t value)
{
    lv_style_set_text_color(&m_pStyle, value);
}

void CStyleHandle::setTextColorFiltered(lv_color_t value)
{
    lv_style_set_text_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setTextOpa(lv_opa_t value)
{
    lv_style_set_text_opa(&m_pStyle, value);
}

void CStyleHandle::setTextFont(const lv_font_t *value)
{
    lv_style_set_text_font(&m_pStyle, value);
}

void CStyleHandle::setTextLetterSpace(lv_coord_t value)
{
    lv_style_set_text_letter_space(&m_pStyle, value);
}

void CStyleHandle::setTextLineSpace(lv_coord_t value)
{
    lv_style_set_text_line_space(&m_pStyle, value);
}

void CStyleHandle::setTextDecor(lv_text_decor_t value)
{
    lv_style_set_text_decor(&m_pStyle, value);
}

void CStyleHandle::setTextAlign(lv_text_decor_t value)
{
    lv_style_set_text_align(&m_pStyle, value);
}

void CStyleHandle::setImgOpa(lv_opa_t value)
{
    lv_style_set_img_opa(&m_pStyle, value);
}

void CStyleHandle::setImgRecolor(lv_color_t value)
{
    lv_style_set_img_recolor(&m_pStyle, value);
}

void CStyleHandle::setImgRecolorFiltered(lv_color_t value)
{
    lv_style_set_img_recolor_filtered(&m_pStyle, value);
}

void CStyleHandle::setImgRecolorOpa(lv_opa_t value)
{
    lv_style_set_img_recolor_opa(&m_pStyle, value);
}

void CStyleHandle::setOutlineWidth(lv_coord_t value)
{
    lv_style_set_outline_width(&m_pStyle, value);
}

void CStyleHandle::setShadowWidth(lv_coord_t value)
{
    lv_style_set_shadow_width(&m_pStyle, value);
}

void CStyleHandle::setShadowOfsX(lv_coord_t value)
{
    lv_style_set_shadow_ofs_x(&m_pStyle, value);
}

void CStyleHandle::setShadowOfsY(lv_coord_t value)
{
    lv_style_set_shadow_ofs_y(&m_pStyle, value);
}

void CStyleHandle::setShadowSpread(lv_coord_t value)
{
    lv_style_set_shadow_spread(&m_pStyle, value);
}

void CStyleHandle::setShadowColor(lv_color_t value)
{
    lv_style_set_shadow_color(&m_pStyle, value);
}

void CStyleHandle::setOutlineColor(lv_color_t value)
{
    lv_style_set_outline_color(&m_pStyle, value);
}

void CStyleHandle::setOutlineColorFiltered(lv_color_t value)
{
    lv_style_set_outline_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setOutlineOpa(lv_opa_t value)
{
    lv_style_set_outline_opa(&m_pStyle, value);
}

void CStyleHandle::setOutlinePad(lv_coord_t value)
{
    lv_style_set_outline_pad(&m_pStyle, value);
}

void CStyleHandle::setShadowColorFiltered(lv_color_t value)
{
    lv_style_set_shadow_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setShadowOpa(lv_opa_t value)
{
    lv_style_set_shadow_opa(&m_pStyle, value);
}

void CStyleHandle::setLineWidth(lv_coord_t value)
{
    lv_style_set_line_width(&m_pStyle, value);
}

void CStyleHandle::setLineDashWidth(lv_coord_t value)
{
    lv_style_set_line_dash_width(&m_pStyle, value);
}

void CStyleHandle::setLineDashGap(lv_coord_t value)
{
    lv_style_set_line_dash_gap(&m_pStyle, value);
}

void CStyleHandle::setLineRounded(bool value)
{
    lv_style_set_line_rounded(&m_pStyle, value);
}

void CStyleHandle::setLineColor(lv_color_t value)
{
    lv_style_set_line_color(&m_pStyle, value);
}

void CStyleHandle::setLineColorFiltered(lv_color_t value)
{
    lv_style_set_line_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setLineOpa(lv_opa_t value)
{
    lv_style_set_line_opa(&m_pStyle, value);
}

void CStyleHandle::setArcWidth(lv_coord_t value)
{
    lv_style_set_arc_width(&m_pStyle, value);
}

void CStyleHandle::setArdRounded(bool value)
{
    lv_style_set_arc_rounded(&m_pStyle, value);
}

void CStyleHandle::setArcColor(lv_color_t value)
{
    lv_style_set_arc_color(&m_pStyle, value);
}

void CStyleHandle::setArcColorFiltered(lv_color_t value)
{
    lv_style_set_arc_color_filtered(&m_pStyle, value);
}

void CStyleHandle::setArcOpa(lv_opa_t value)
{
    lv_style_set_arc_opa(&m_pStyle, value);
}

void CStyleHandle::setArcImgSrc(const void *value)
{
    lv_style_set_arc_img_src(&m_pStyle, value);
}