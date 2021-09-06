#include"x64.h"

using namespace x64;

namespace x64::Regs{
    const GPR RAX{BaseReg::Group::GPR64, 0};
    const GPR EAX{BaseReg::Group::GPR32, 0};
    const GPR AX{BaseReg::Group::GPR16, 0};

    const GPR RBX{BaseReg::Group::GPR64, 3};
    const GPR EBX{BaseReg::Group::GPR32, 3};
    const GPR EX{BaseReg::Group::GPR16, 3};

    const GPR RCX{BaseReg::Group::GPR64, 1};
    const GPR ECX{BaseReg::Group::GPR32, 1};
    const GPR CX{BaseReg::Group::GPR16, 1};

    const GPR RDX{BaseReg::Group::GPR64, 2};
    const GPR EDX{BaseReg::Group::GPR32, 2};
    const GPR DX{BaseReg::Group::GPR16, 2};

    const GPR RDI{BaseReg::Group::GPR64, 7};
    const GPR EDI{BaseReg::Group::GPR32, 7};
    const GPR DI{BaseReg::Group::GPR16, 7};
};
Address GPR::operator+(size_t val) const noexcept { 
    return Address{*this} + val;
}
Address GPR::operator-(size_t val) const noexcept { 
    return Address{*this} - val;
}
Address GPR::operator+(RefReg reg) const noexcept {  
    return Address(*this, 1) + reg;
}
Address GPR::operator*(size_t val) const noexcept { 
    return Address{*this, val};
}
Address operator+(size_t val, RefReg reg) noexcept{
    return Address{val} + reg;
}

