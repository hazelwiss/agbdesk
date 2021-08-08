#pragma once
#include<common.h>

template<size_t bits>
struct Int{
    Int() = default;
    Int(size_t val): val{val} {}
    static_assert(bits <= 64, "a higher bitcount than 64 is unsupported");
    template<typename T> constexpr T operator()(T) const noexcept requires std::is_fundamental<T>::value { return val; }
    template<typename T> constexpr T operator+(T op) const noexcept requires std::is_fundamental<T>::value { return val + op; }
    template<typename T> constexpr T operator-(T op) const noexcept requires std::is_fundamental<T>::value { return val - op; }
    template<typename T> constexpr T operator/(T op) const noexcept requires std::is_fundamental<T>::value { return val / op; }
    template<typename T> constexpr T operator*(T op) const noexcept requires std::is_fundamental<T>::value { return val * op; }
    template<typename T> constexpr T operator<<(T op) const noexcept requires std::is_fundamental<T>::value { return val << op; }
    template<typename T> constexpr T operator>>(T op) const noexcept requires std::is_fundamental<T>::value { return val >> op; }
    template<typename T> constexpr T operator&(T op) const noexcept requires std::is_fundamental<T>::value { return val & op; }
    template<typename T> constexpr T operator|(T op) const noexcept requires std::is_fundamental<T>::value { return val | op; }
    template<typename T> constexpr T operator^(T op) const noexcept requires std::is_fundamental<T>::value { return val ^ op; }
    template<typename T> constexpr T operator%(T op) const noexcept requires std::is_fundamental<T>::value { return val % op; }
    constexpr size_t operator~() const noexcept { return ~val; }
    template<typename T> constexpr T& operator+=(T op) noexcept requires std::is_fundamental<T>::value { return val += op; }
    template<typename T> constexpr T& operator-=(T op) noexcept requires std::is_fundamental<T>::value { return val -= op; }
    template<typename T> constexpr T& operator/=(T op) noexcept requires std::is_fundamental<T>::value { return val /= op; }
    template<typename T> constexpr T& operator*=(T op) noexcept requires std::is_fundamental<T>::value { return val *= op; }
    template<typename T> constexpr T& operator<<=(T op) noexcept requires std::is_fundamental<T>::value { return val <<= op; }
    template<typename T> constexpr T& operator>>=(T op) noexcept requires std::is_fundamental<T>::value { return val >>= op; }
    template<typename T> constexpr T& operator&=(T op) noexcept requires std::is_fundamental<T>::value { return val &= op; }
    template<typename T> constexpr T& operator|=(T op) noexcept requires std::is_fundamental<T>::value { return val |= op; }
    template<typename T> constexpr T& operator^=(T op) noexcept requires std::is_fundamental<T>::value { return val ^= op; }
    template<typename T> constexpr T& operator%=(T op) noexcept requires std::is_fundamental<T>::value { return val %= op; }
    size_t val: bits{0};
};