#pragma once
#include<cstdint>
#include<stddef.h>

enum class UNIT{B = 1, KB = 1024, MB = KB*KB};

template<UNIT U>
struct Unit{
    constexpr Unit(double quant): quant{quant} {};
    const UNIT UT{U};
    double quant;
};

struct UnitConverter{
    template<UNIT TO, UNIT FROM> static constexpr Unit<TO> convert(const Unit<FROM>& a) noexcept { return a.quant*((double)a.UT/(double)TO); } 
};

namespace GBAInfo{
    constexpr size_t MEMORY_SIZE = 0x100000000;
};