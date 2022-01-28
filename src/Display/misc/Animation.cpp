#include "Animation.h"

CAnimation::~CAnimation()
{
    
}

void CAnimation::create()
{
    lv_anim_init(&m_animation);
    setUserData(this);
    setVariable(&m_animation);
    //lv_anim_set_exec_cb(&m_animation, &CAnimation::executionCallback);
    lv_anim_set_custom_exec_cb(&m_animation, &CAnimation::executionCallback);
    /*lv_anim_set_path_cb(&m_animation, &CAnimation::pathCallback);
    lv_anim_set_start_cb(&m_animation, &CAnimation::startCallback);
    lv_anim_set_get_value_cb(&m_animation, &CAnimation::getValueCallback);
    lv_anim_set_ready_cb(&m_animation, &CAnimation::readyCallback);*/
}

lv_anim_t* CAnimation::start()
{
    return lv_anim_start(&m_animation);
}

uint32_t CAnimation::getPlaytime()
{
    return lv_anim_get_playtime(&m_animation);
}

void CAnimation::setVariable(void* object)
{
    lv_anim_set_var(&m_animation, object);
}

bool CAnimation::del(void* var, lv_anim_exec_xcb_t exec_cb)
{
    return lv_anim_del(var, exec_cb);
}

void CAnimation::delAll()
{
    lv_anim_del_all();
}

lv_anim_t* CAnimation::get(void * var, lv_anim_exec_xcb_t exec_cb)
{
    return lv_anim_get(var, exec_cb);
}

uint16_t CAnimation::getCountRunning()
{
    return lv_anim_count_running();
}

uint32_t CAnimation::getSpeedToTime(uint32_t speed, int32_t start, int32_t end)
{
    return lv_anim_speed_to_time(speed, start, end);
}

void CAnimation::refreshNow()
{
    lv_anim_refr_now();
}

int32_t CAnimation::getPathLinear()
{
    return lv_anim_path_linear(&m_animation);
}

int32_t CAnimation::getPathEaseIn()
{
    return lv_anim_path_ease_in(&m_animation);
}

int32_t CAnimation::getPathEaseOut()
{
    return lv_anim_path_ease_out(&m_animation);
}

int32_t CAnimation::getPathEaseInOut()
{
    return lv_anim_path_ease_in_out(&m_animation);
}

int32_t CAnimation::getPathOvershoot()
{
    return lv_anim_path_overshoot(&m_animation);
}

int32_t CAnimation::getPathBounce()
{
    return lv_anim_path_bounce(&m_animation);
}

int32_t CAnimation::getPathStep()
{
    return lv_anim_path_step(&m_animation);
}

void CAnimation::setTime(uint32_t duration)
{
    lv_anim_set_time(&m_animation, duration);
}

void CAnimation::setDelay(uint32_t delay)
{
    lv_anim_set_delay(&m_animation, delay);
}

void CAnimation::setValues(int32_t start, int32_t end)
{
    lv_anim_set_values(&m_animation, start, end);
}

void CAnimation::setPlaybackTime(uint32_t time)
{
    lv_anim_set_playback_time(&m_animation, time);
}

void CAnimation::setPlaybackDelay(uint32_t delay)
{
    lv_anim_set_playback_delay(&m_animation, delay);
}

void CAnimation::setRepeatCount(uint16_t cnt)
{
    lv_anim_set_repeat_count(&m_animation, cnt);
}

void CAnimation::setRepeatDelay(uint32_t delay)
{
    lv_anim_set_repeat_delay(&m_animation, delay);
}

void CAnimation::setEarlyApply(bool en)
{
    lv_anim_set_early_apply(&m_animation, en);
}

uint32_t CAnimation::getDelay()
{
    return lv_anim_get_delay(&m_animation);
}

bool CAnimation::customDelete(lv_anim_custom_exec_cb_t exec_cb)
{
    return lv_anim_custom_del(&m_animation, exec_cb);
}

lv_anim_t* CAnimation::customGet(lv_anim_custom_exec_cb_t exec_cb)
{
    return lv_anim_custom_get(&m_animation, exec_cb);
}

void CAnimation::setUserData(void* user_data)
{
    lv_anim_set_user_data(&m_animation, user_data);
}


/*Static callbacks*/
void CAnimation::executionCallback(lv_anim_t* obj, int32_t data)
{
    auto pThis = (CAnimation*)obj->user_data;
    if(pThis)
    {
        pThis->callExecutionCallback(obj, data);
    }
}

int32_t CAnimation::pathCallback(const _lv_anim_t* obj)
{
    auto pThis = static_cast<CAnimation*>(obj->user_data);
    if(pThis && pThis->m_pathCallback)
        return pThis->callPathCallback(obj);
    return -1;
}

void CAnimation::startCallback(_lv_anim_t* obj)
{
    auto pThis = static_cast<CAnimation*>(obj->user_data);
    if(pThis)
        pThis->callStartCallback(obj);
}

int32_t CAnimation::getValueCallback(_lv_anim_t* obj)
{
    auto pThis = static_cast<CAnimation*>(obj->user_data);
    if(pThis)
        return pThis->callGetValueCallback(obj);
    return -1;
}

void CAnimation::readyCallback(_lv_anim_t* obj)
{
    auto pThis = static_cast<CAnimation*>(obj->user_data);
    if(pThis)
        pThis->callReadyCallback(obj);
}

void CAnimation::callExecutionCallback(_lv_anim_t* obj, int32_t data)
{
    if(m_executionCallback)
        m_executionCallback(obj, data);
}

int32_t CAnimation::callPathCallback(const _lv_anim_t* obj)
{
    if(m_pathCallback)
        m_pathCallback(obj);
}

void CAnimation::callStartCallback(_lv_anim_t* obj)
{
    if(m_startCallback)
        m_startCallback(obj);
}

int32_t CAnimation::callGetValueCallback(_lv_anim_t* obj)
{
    if(m_getValueCallback)
        m_getValueCallback(obj);
}

void CAnimation::callReadyCallback(_lv_anim_t* obj)
{
    if(m_readyCallback)
        m_readyCallback(obj);
}
