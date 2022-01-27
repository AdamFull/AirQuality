#pragma once
#include "BaseControl.h"
#include <vector>

class CMessageBox : public CBaseControl
{
public:
    CMessageBox(const std::string& title, const std::string& text, const std::vector<const char*>& btn_txts, bool add_close_btn);
    void create(std::shared_ptr<CBaseControl> pParent) override;

    std::unique_ptr<CBaseControl> getTitle();
    std::unique_ptr<CBaseControl> getCloseButton();
    std::unique_ptr<CBaseControl> getText();
    std::unique_ptr<CBaseControl> getContent();
    std::unique_ptr<CBaseControl> getButtons();
    uint16_t getActiveButton();
    std::string getActiveButtonText();
    void close();
    void closeAsync();
private:
    std::string m_srTitle;
    std::string m_srText;
    std::vector<const char*> m_vButtonTexts;
    bool m_bAddCloseBtn{false};
};