#pragma once
#include "BaseControl.h"
#include "Label.h"
#include "Button.h"
#include <map>
#include <string>

class CList : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    CLabel* addText(const std::string& srName, const std::string& srText);
    CButton* addButton(const std::string& srName, const char * icon, const std::string& srText);
    const char* getButtonText(const std::string& srName);
private:
    std::map<std::string, CBaseControl*> m_pControls;
};