#include"x64.h"

namespace x64{
    Address::Address(RefReg reg) noexcept {
        sib.setBase(reg);
    }
    Address::Address(RefReg reg, size_t scale) noexcept {
        sib.setIndex(reg);
        sib.setScale(scale);
    }
    Address::Address(size_t val) noexcept {
        dispatch = val;
    }
    Address&& Address::operator+(RefReg reg){ 
        if(has_sib_base)
            throw std::runtime_error(ErrStrings::INVEFFECTIVEADR);
        this->sib.setBase(reg);
        has_sib_base = true;
        return std::move(*this); 
    }
    Address&& Address::operator+(Disp val){ 
        if(has_disp)
            throw std::runtime_error(ErrStrings::INVEFFECTIVEADR);
        dispatch = val;
        has_disp = true;
        return std::move(*this); 
    }
    Address&& Address::operator*(size_t val){ 
        if(has_sib_scale)
            throw std::runtime_error(ErrStrings::INVEFFECTIVEADR);
        if(val%2 != 0)
            throw std::runtime_error(ErrStrings::INVEFFECTIVEADR);
        sib.setScale(val);
        has_sib_scale = true;
        return std::move(*this); 
    }
    Address&& operator+(RefReg reg, Address&& adr){
        adr = adr + reg;
        return std::move(adr);
    }
    Address&& operator+(size_t val, Address&& adr){
        adr = adr + val;
        return std::move(adr);
    }
};
