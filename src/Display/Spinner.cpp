#include "Spinner.h"

void CSpinner::create(lv_obj_t* pParent)
{
    m_pInstance.reset(lv_spinner_create(pParent, 1, 10));
    CBaseControl::create(pParent);
}