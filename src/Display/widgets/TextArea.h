#pragma once
#include "BaseControl.h"

class CTextArea : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;

    void addChar(uint32_t c);
    void addText(const std::string& srText);
    void delChar();
    void delCharForward();
    void setText(const std::string& srText);
    void setTextPlaceholder(const std::string& srText);
    void setCorsorPos(int32_t pos);
    void setCursorClickPos(bool en);
    void setPasswordMode(bool en);
    void setOneLine(bool en);
    void setAcceptedChars(const std::string& srText);
    void setMaxLength(uint32_t num);
    void setInsertReplace(const std::string& srText);
    void setTextSelection(bool en);
    void setPasswordShowTime(uint16_t time);
    void setTextAlign(lv_text_align_t align);

    std::string getText();
    std::string getPlaceholderText();
    lv_obj_t* getLabel();
    uint32_t getCursorPos();
    bool getCursorClickPos();
    bool getPasswordMode();
    bool getOneLine();
    std::string getAcceptedChars();
    uint32_t getMaxLength();
    bool isSelected();
    bool getTextSelected();
    uint16_t getTextShowTime();

    void clearSelection();
    void cursorRight();
    void cursorLeft();
    void cursorDown();
    void cursorUp();
};