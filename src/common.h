/*
    This header includes commonly used information as to pack it into a single file, easy for anything to include and not particularly heavy.
    It contains basic type definitions(size_t, uint32_t, and so on), their limits, as well as some useful structs. 
*/

#pragma once
#include<cstdint>
#include<stddef.h>
#include<stdexcept>
#include<climits>

/*
    Basic enum definition for unit conversion.
*/
enum class Units{B = 1, KB = 1024, MB = KB*KB};

/*
    Stores the a 64 bit value of a particular unit. Useful for converting different units.
*/
template<Units U>
struct Unit{
    constexpr Unit(uint64_t quant): QUANT{quant} {};
    const Units UNIT_TYPE{U};
    const uint64_t QUANT;
};

/*
    Converts a value of one particular unit to be expressed as the equivalent value in another unit. 
*/
struct UnitConverter{
    template<Units to, Units from> static constexpr Unit<to> convert(const Unit<from>& a) noexcept 
        { return a.quant*((double)a.UNIT_TYPE/(double)to); } 
};

/*
    Basic struct for keeping general information of the GBA.
*/
namespace GBAInfo{
    constexpr size_t MEMORY_SIZE = 0x100000000;
};

