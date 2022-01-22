#pragma once

#include <optional>
#include <functional>

template <class T>
struct NotifyProperty
{
public:
    NotifyProperty() = default;

    NotifyProperty(const T &val) { value = val; }
    ~NotifyProperty() { notify = nullptr; }

    inline const std::optional<T>& get() const { return value; }
    inline void bind(const std::function<void(const T&)> &cb) { notify = cb; }

    inline T& operator=(const T &val)
    {
        if (notify && last_changed != val)
        {
            notify(val);
            value = val;
            last_changed = val;
        }
        return last_changed;
    }

private:
    T last_changed{NULL};
    std::optional<T> value{T()};
    std::function<void(const T&)> notify{nullptr};
};

using notify_int8_t = NotifyProperty<int8_t>;
using notify_uint8_t = NotifyProperty<uint8_t>;
using notify_int16_t = NotifyProperty<int16_t>;
using notify_uint16_t = NotifyProperty<uint16_t>;
using notify_int32_t = NotifyProperty<int32_t>;
using notify_uint32_t = NotifyProperty<uint32_t>;
using notify_int64_t = NotifyProperty<int64_t>;
using notify_uint64_t = NotifyProperty<uint64_t>;

using notify_bool = NotifyProperty<bool>;

using notify_float = NotifyProperty<float>;
using notify_double = NotifyProperty<double>;