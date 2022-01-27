#pragma once
#include "BaseControl.h"

class CCheckBox : public CBaseControl
{
public:
    void create(std::shared_ptr<CBaseControl> pParent) override;

    void setText(const std::string& srText);
    void setTextStatic(const std::string& srText);
    
    std::string getText();
};