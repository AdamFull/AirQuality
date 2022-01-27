#pragma once
#include <functional>

template <class _Class, class _ReturnType, class... Args>
inline std::function<_ReturnType(Args...)> make_func(_Class *c, _ReturnType (_Class::*m)(Args...)) noexcept
{
    return [=](Args &&...args)
    { 
        return (c->*m)(std::forward<Args>(args)...);
    };
}

template <class _Class, class _ReturnType, class... Args>
inline std::function<_ReturnType(Args...)> make_func(const _Class *c, _ReturnType (_Class::*m)(Args...) const) noexcept
{
    return [=](Args &&...args)
    { 
        return (c->*m)(std::forward<Args>(args)...);
    };
}