#pragma once
#include <lvgl.h>
#include <memory>

class CStyleHandle
{
public:
    void create();

    void reset();
    void removeProp(lv_style_prop_t prop);
    void setProp(lv_style_prop_t prop, lv_style_value_t value);
    std::pair<lv_res_t, lv_style_value_t> getProp(lv_style_prop_t prop);
    bool isEmpty();
    lv_style_t* get();

    void setWidth(lv_coord_t value);
    void setMinWidth(lv_coord_t value);
    void setMaxWidth(lv_coord_t value);
    void setHeight(lv_coord_t value);
    void setMinHeight(lv_coord_t value);
    void setMaxHeight(lv_coord_t value);
    void setX(lv_coord_t value);
    void setY(lv_coord_t value);
    void setAlign(lv_coord_t value);
    void setTransformWidth(lv_coord_t value);
    void setTransformHeight(lv_coord_t value);
    void setTranslateX(lv_coord_t value);
    void setTranslateY(lv_coord_t value);
    void setTransformZoom(lv_coord_t value);
    void setTransformAngle(lv_coord_t value);
    void setPadTop(lv_coord_t value);
    void setPadBottom(lv_coord_t value);
    void setPadLeft(lv_coord_t value);
    void setPadRight(lv_coord_t value);
    void setPadRow(lv_coord_t value);
    void setPadColumt(lv_coord_t value);
    void setRadius(lv_coord_t value);
    void setClipCorner(bool value);
    void setOpa(lv_opa_t value);
    void setColorFilterDsc(const lv_color_filter_dsc_t *value);
    void setColorFilterOpa(lv_opa_t value);
    void setAnimTime(uint32_t value);
    void setAnimSpeed(uint32_t value);
    void setTranslation(const lv_style_transition_dsc_t *value);
    void setBlendMode(lv_blend_mode_t value);
    void setLayout(uint16_t value);
    void setBaseDir(lv_base_dir_t value);
    void setBgColor(lv_color_t value);
    void setBgColorFiltered(lv_color_t value);
    void setBgOpa(lv_opa_t value);
    void setBgGradColor(lv_color_t value);
    void setBgGradColorFiltered(lv_color_t value);
    void setBgGradDir(lv_grad_dir_t value);
    void setBgMainStop(lv_coord_t value);
    void setBgGradStop(lv_coord_t value);
    void setBgImgSrc(const void *value);
    void setBgImgOpa(lv_opa_t value);
    void setBgImgRecolor(lv_color_t value);
    void setBgImgRecolorFiltered(lv_color_t value);
    void setBgImgRecolorOpa(lv_opa_t value);
    void setBgImgTiled(bool value);
    void setBorderColor(lv_color_t value);
    void setBorderColorFiltered(lv_color_t value);
    void setBorderOpa(lv_opa_t value);
    void setBorderWidth(lv_coord_t value);
    void setBorderSide(lv_border_side_t value);
    void setBorderPost(bool value);
    void setTextColor(lv_color_t value);
    void setTextColorFiltered(lv_color_t value);
    void setTextOpa(lv_opa_t value);
    void setTextFont(const lv_font_t *value);
    void setTextLetterSpace(lv_coord_t value);
    void setTextLineSpace(lv_coord_t value);
    void setTextDecor(lv_text_decor_t value);
    void setTextAlign(lv_text_decor_t value);
    void setImgOpa(lv_opa_t value);
    void setImgRecolor(lv_color_t value);
    void setImgRecolorFiltered(lv_color_t value);
    void setImgRecolorOpa(lv_opa_t value);
    void setOutlineWidth(lv_coord_t value);
    void setShadowWidth(lv_coord_t value);
    void setShadowOfsX(lv_coord_t value);
    void setShadowOfsY(lv_coord_t value);
    void setShadowSpread(lv_coord_t value);
    void setShadowColor(lv_color_t value);
    void setOutlineColor(lv_color_t value);
    void setOutlineColorFiltered(lv_color_t value);
    void setOutlineOpa(lv_opa_t value);
    void setOutlinePad(lv_coord_t value);
    void setShadowColorFiltered(lv_color_t value);
    void setShadowOpa(lv_opa_t value);
    void setLineWidth(lv_coord_t value);
    void setLineDashWidth(lv_coord_t value);
    void setLineDashGap(lv_coord_t value);
    void setLineRounded(bool value);
    void setLineColor(lv_color_t value);
    void setLineColorFiltered(lv_color_t value);
    void setLineOpa(lv_opa_t value);
    void setArcWidth(lv_coord_t value);
    void setArdRounded(bool value);
    void setArcColor(lv_color_t value);
    void setArcColorFiltered(lv_color_t value);
    void setArcOpa(lv_opa_t value);
    void setArcImgSrc(const void *value);
private:
    lv_style_t m_pStyle;
};
