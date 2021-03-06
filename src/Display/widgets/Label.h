#pragma once
#include "BaseControl.h"
#include <sstream>

class CLabel : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;
    void create(std::shared_ptr<CBaseControl>, std::shared_ptr<CBaseControl> pPtr) override; 
    
    void setText(const std::string& srText);

    template<class T>
    void setValue(T value)
    {
        std::stringstream ss;
        ss << value;
        setText(ss.str());
    }

    void setValueRanged(int16_t from, int16_t to);

    template<class... Args>
    void setTextFormat(Args &&...args)
    {
        lv_label_set_text_fmt(m_pInstance.get(), std::forward<Args>(args)...);
    }

    void setLondMode(const lv_label_long_mode_t& mode);
    void setRecolor(bool bValue);
    void setTextSelStart(uint32_t index);
    void setTextSelEnd(uint32_t index);

    std::string getText();
    lv_label_long_mode_t getLongMode();
    bool getRecolor();
    lv_point_t getLetterPos(uint32_t id);
    uint32_t getLetterOn(lv_point_t* pos);
    bool isCharUnderPos(lv_point_t* pos);
    uint32_t getTextSelectionStart();
    uint32_t getTextSelectionEnd();

    void insert(const std::string& srText, uint32_t pos);
    void cut(uint32_t pos, uint32_t count);
};