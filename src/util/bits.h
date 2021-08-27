#pragma once
#include<utility>
#include<type_traits>
#include<common.h>


constexpr size_t DetermineMinBits(size_t val)
    { if(!val) return 0; size_t r = 0; while(++r, val>>=1); return r; }

template<size_t bits = 0>
struct BitsMax{
    static_assert(bits <= 128, "cannot determine maximum size of integer with more than 128 bits.");
    BitsMax() = delete;
    BitsMax(size_t numbits){
        if(numbits > 64)
            throw std::runtime_error("cannot determine maximum size of integer with more than 64 bits.");
        for(size_t bit = 0; bit < numbits; ++bit) 
            _max|=(uint64_t)1 << bit;
    }
    static constexpr __int128_t max(){ return static_max; }
    uint64_t get() const{ return _max; }
protected:
    static inline constexpr __int128 static_max = []()consteval->__int128{ 
        __int128 rtrn = 0;
        for(size_t bit = 0; bit < bits; ++bit) 
            rtrn|=(__int128)1 << bit;
        return rtrn;
    }();
    uint64_t _max{0};
};

struct Bits{
    Bits() = delete;
    constexpr Bits(size_t num, size_t beg, size_t amount = 1){ value = (num>>beg) & BitsMax{amount}.get(); }
    uint64_t get(){ return value; }
protected:
    uint64_t value;
};