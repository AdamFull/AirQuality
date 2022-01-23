/*#include "NextionHandler.hpp"

NextionHandler::~NextionHandler()
{
    for(auto& [key, val] : m_ctrls)
    {
        delete val;
    }
    m_ctrls.clear();
}

bool NextionHandler::Create(uint32_t bauds)
{
    HMISerial = std::make_unique<SoftwareSerial>(HMI_RX, HMI_TX);
    HMISerial->begin(bauds);
    m_pDisplay = Nextion::GetInstance(*HMISerial.get());

    return m_pDisplay && m_pDisplay->nexInit(bauds);
}*/