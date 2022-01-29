#pragma once

#include <optional>
#include <functional>
#include <numeric>
#include <stdint.h>
#include <variant>
#include <type_traits>
#include <cmath>

namespace react
{
    constexpr const uint16_t mean_max{20};

    template <class T>
    struct NotifyProperty 
    {
        /*static_assert(std::is_object<T>::value && 
        std::is_void<T>::value, 
        "Type is not arithmetic or void. NotifyProperty support only arithmetic types except for void.");*/
    public:
        NotifyProperty() = default;

        NotifyProperty(const T &val) { value = val; }
        ~NotifyProperty() { notify = nullptr; }

        inline const std::optional<T>& get() const { return value; }
        template<class _lambdaexpr>
        inline void bind(_lambdaexpr&& cb) noexcept
        { 
            notify = std::forward<_lambdaexpr>(cb); 
        }

        template<class _Class, class _ReturnType, class... Args>
        void bind(_Class *c, _ReturnType (_Class::*m)(Args...))
        {
            notify = make_func(c, m);
        }


        inline T& operator=(const T &val) noexcept
        {
            if (notify && !ncompare(last_changed, val))
            {

                std::rotate(buffer.begin(), buffer.begin() + 1, buffer.end());
                buffer.back() = val;

                T mean = std::accumulate(buffer.begin(), buffer.end(), 0) / mean_max;

                notify(last_changed, val);
                last_changed = value.value_or(0);
                value = val;
            }
            return last_changed;
        }

        const std::array<T, mean_max>& GetBuffer()
        {
            return buffer;
        }

    private:
        constexpr std::enable_if<std::is_floating_point<T>::value, bool>
        ncompare(const T& first, const T& second)
        {
            return std::fabs(first - second) <= std::numeric_limits<T>::epsilon();
        }

        constexpr std::enable_if<!std::is_floating_point<T>::value, bool>
        ncompare(const T& first, const T& second)
        {
            return first == second;
        }

        std::array<T, mean_max> buffer{0};
        T last_changed{NULL};
        std::optional<T> value{T()};
        std::function<void(const T&, const T&)> notify{nullptr};
    };


    using rint8_t = NotifyProperty<int8_t>;
    using ruint8_t = NotifyProperty<uint8_t>;
    using rint16_t = NotifyProperty<int16_t>;
    using ruint16_t = NotifyProperty<uint16_t>;
    using rint32_t = NotifyProperty<int32_t>;
    using ruint32_t = NotifyProperty<uint32_t>;
    using rint64_t = NotifyProperty<int64_t>;
    using ruint64_t = NotifyProperty<uint64_t>;

    using rbool = NotifyProperty<bool>;

    using rfloat = NotifyProperty<float>;
    using rdouble = NotifyProperty<double>;

    using variants = std::variant<rint8_t, ruint8_t, rint16_t, ruint16_t, rint32_t, ruint32_t, rint64_t, ruint64_t, rbool, rfloat, rdouble>;

    template<class T, class _variant>
    struct is_variant_type;

    template<class T, class... Args>
    struct is_variant_type<T, std::variant<Args...>> 
    : public std::disjunction<std::is_same<T, Args>...> {};

    template<class T>
    using is_react_value = is_variant_type<T, variants>;
}