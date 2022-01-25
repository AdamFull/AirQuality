#pragma once
#include "BaseControl.h"

class CCheckBox : public CBaseControl
{
public:
    void create(lv_obj_t* pParent) override;

    void setText(const std::string& srText);
    void setTextStatic(const std::string& srText);
    
    std::string getText();
};