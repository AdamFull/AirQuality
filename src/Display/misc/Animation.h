#pragma once
#include <Display/widgets/BaseControl.h>

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
    template<class... Args>
    void setExecutionCallback(Args... args)
    {
       m_executionCallback = std::move(EasyDelegate::TDelegate<void(lv_anim_t*, int32_t)>(std::forward<Args>(args)...));
    }

    template<class... Args>
    void setPathCallback(Args... args)
    {
       m_pathCallback = std::move(EasyDelegate::TDelegate<int32_t(const lv_anim_t*)>(std::forward<Args>(args)...));
    }
    
    template<class... Args>
    void setStartCallback(Args... args)
    {
       m_startCallback = std::move(EasyDelegate::TDelegate<void(lv_anim_t*)>(std::forward<Args>(args)...));
    }

    template<class... Args>
    void setGetValueCallback(Args... args)
    {
       m_getValueCallback = std::move(EasyDelegate::TDelegate<int32_t(lv_anim_t*)>(std::forward<Args>(args)...));
    }
    
    template<class... Args>
    void setReadyCallback(Args... args)
    {
       m_readyCallback = std::move(EasyDelegate::TDelegate<void(lv_anim_t*)>(std::forward<Args>(args)...));
    }    

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

    EasyDelegate::TDelegate<void(lv_anim_t*, int32_t)> m_executionCallback{nullptr};
    EasyDelegate::TDelegate<int32_t(const lv_anim_t*)> m_pathCallback{nullptr};
    EasyDelegate::TDelegate<void(lv_anim_t*)> m_startCallback{nullptr};
    EasyDelegate::TDelegate<int32_t(lv_anim_t*)> m_getValueCallback{nullptr};
    EasyDelegate::TDelegate<void(lv_anim_t*)> m_readyCallback{nullptr};

    CBaseControl* m_pObject{nullptr};
    lv_anim_t m_animation;
};

