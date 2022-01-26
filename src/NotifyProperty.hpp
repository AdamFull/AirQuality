#pragma once

#include <optional>
#include <functional>
#include <numeric>
#include <stdint.h>

constexpr const uint16_t mean_max{20};

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
            std::rotate(buffer.begin(), buffer.begin() + 1, buffer.end());
            buffer.back() = val;

            notify(std::accumulate(buffer.begin(), buffer.end(), 0) / mean_max);
            value = val;
            last_changed = val;
        }
        return last_changed;
    }

    const std::array<T, mean_max>& GetBuffer()
    {
        return buffer;
    }

private:
    std::array<T, mean_max> buffer{0};
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