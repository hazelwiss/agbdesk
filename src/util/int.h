#pragma once
#include<common.h>

template<size_t bits>
struct Int{
    static_assert(bits <= 64, "a higher bitcount than 64 is unsupported");
    static_assert(bits != 0, "custom integer type cannot have size of 0");
    constexpr Int() = default;
    constexpr Int(size_t val): val{val} {}
    constexpr bool getBit(size_t bit) const noexcept { return (val >> bit)&1; }
    constexpr size_t getVal() const noexcept { return val; } 
    template<typename T> constexpr operator T() const noexcept requires std::is_fundamental<T>::value { return val; }
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