#pragma once
#include <Display/widgets/BaseControl.h>
#include <Arduino.h>

class CAnimation
{
public:
    CAnimation() = default;
    ~CAnimation();
    void create();

    lv_anim_t* start();
    uint32_t getPlaytime();
    static bool del(void* var, lv_anim_exec_xcb_t exec_cb);
    static void delAll();
    static lv_anim_t* get(void * var, lv_anim_exec_xcb_t exec_cb);
    static uint16_t getCountRunning();
    static uint32_t getSpeedToTime(uint32_t speed, int32_t start, int32_t end);
    static void refreshNow();
    int32_t getPathLinear();
    int32_t getPathEaseIn();
    int32_t getPathEaseOut();
    int32_t getPathEaseInOut();
    int32_t getPathOvershoot();
    int32_t getPathBounce();
    int32_t getPathStep();

    void setTime(uint32_t duration);
    void setDelay(uint32_t delay);
    void setValues(int32_t start, int32_t end);
    void setPlaybackTime(uint32_t time);
    void setPlaybackDelay(uint32_t delay);
    void setRepeatCount(uint16_t cnt);
    void setRepeatDelay(uint32_t delay);
    void setEarlyApply(bool en);
    uint32_t getDelay();
    bool customDelete(lv_anim_custom_exec_cb_t exec_cb);
    lv_anim_t* customGet(lv_anim_custom_exec_cb_t exec_cb);

    /* callbacks */

    template<class _lambdaexpr>
    void setExecutionCallback(_lambdaexpr&& lexpr) { m_executionCallback = std::forward<_lambdaexpr>(lexpr); }

    template<class _Class, class _ReturnType, class... Args>
    void setExecutionCallback(_Class *c, _ReturnType (_Class::*m)(Args...)) { m_executionCallback = std::move(make_func(c, m)); }

    template<class _lambdaexpr>
    void setPathCallback(_lambdaexpr&& lexpr) { m_pathCallback = std::forward<_lambdaexpr>(lexpr); }

    template<class _Class, class _ReturnType, class... Args>
    void setPathCallback(_Class *c, _ReturnType (_Class::*m)(Args...)) { m_pathCallback = std::move(make_func(c, m)); }

    template<class _lambdaexpr>
    void setStartCallback(_lambdaexpr&& lexpr) { m_startCallback = std::forward<_lambdaexpr>(lexpr); }

    template<class _Class, class _ReturnType, class... Args>
    void setStartCallback(_Class *c, _ReturnType (_Class::*m)(Args...)) { m_startCallback = std::move(make_func(c, m)); }

    template<class _lambdaexpr>
    void setGetValueCallback(_lambdaexpr&& lexpr) { m_getValueCallback = std::forward<_lambdaexpr>(lexpr); }

    template<class _Class, class _ReturnType, class... Args>
    void setGetValueCallback(_Class *c, _ReturnType (_Class::*m)(Args...)) { m_getValueCallback = std::move(make_func(c, m)); }

    template<class _lambdaexpr>
    void setReadyCallback(_lambdaexpr&& lexpr) { m_readyCallback = std::forward<_lambdaexpr>(lexpr); }

    template<class _Class, class _ReturnType, class... Args>
    void setReadyCallback(_Class *c, _ReturnType (_Class::*m)(Args...)) { m_readyCallback = std::move(make_func(c, m)); }

    /* user data*/

    void setUserData(void* user_data);

    template<class T>
    T* getUserData()
    {
        return static_cast<T*>(lv_anim_get_user_data(&m_animation));
    }

private:
    /*No needed for user anymore. Use lambda capture!*/
    void setVariable(void* object);

    static void executionCallback(lv_anim_t* obj, int32_t data);
    static int32_t pathCallback(const lv_anim_t* obj);
    static void startCallback(lv_anim_t* obj);
    static int32_t getValueCallback(lv_anim_t*);
    static void readyCallback(lv_anim_t*);

    void callExecutionCallback(lv_anim_t* obj, int32_t data);
    int32_t callPathCallback(const lv_anim_t* obj);
    void callStartCallback(lv_anim_t* obj);
    int32_t callGetValueCallback(lv_anim_t* obj);
    void callReadyCallback(lv_anim_t* obj);

    std::function<void(lv_anim_t*, int32_t)> m_executionCallback{nullptr};
    std::function<int32_t(const lv_anim_t*)> m_pathCallback{nullptr};
    std::function<void(lv_anim_t*)> m_startCallback{nullptr};
    std::function<int32_t(lv_anim_t*)> m_getValueCallback{nullptr};
    std::function<void(lv_anim_t*)> m_readyCallback{nullptr};

    CBaseControl* m_pObject{nullptr};
    lv_anim_t m_animation;
};

