#include "Spinner.h"

CSpinner::CSpinner(uint32_t time, uint32_t arc_length) :
    m_timeMs(time), m_arcLength(arc_length)
{

}

void CSpinner::create(std::shared_ptr<CBaseControl> pParent)
{
    m_pInstance.reset(lv_spinner_create(pParent->getObj(), m_timeMs, m_arcLength));
    CBaseControl::create(pParent);
}