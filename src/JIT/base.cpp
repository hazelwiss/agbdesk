#include"base.h"
#include<array>
#include<cstring>

constexpr std::array<size_t, 6> reg_size_lut = []()consteval{
    auto ret = decltype(reg_size_lut){};
    ret[BaseReg::Group::None]       = 0;
    ret[BaseReg::Group::GPR8Lo]     = 1;
    ret[BaseReg::Group::GPR8Hi]     = 1;
    ret[BaseReg::Group::GPR16]      = 2;
    ret[BaseReg::Group::GPR32]      = 4;
    ret[BaseReg::Group::GPR64]      = 8;
    return ret;
}();

constexpr std::array<size_t, 5> mem_size_lut = []()consteval{
    auto ret = decltype(mem_size_lut){};
    ret[BaseMem::Group::None]   = 0;
    ret[BaseMem::Group::S8]     = 1;
    ret[BaseMem::Group::S16]    = 2;
    ret[BaseMem::Group::S32]    = 4;
    ret[BaseMem::Group::S64]    = 8;
    return ret;
}();

constexpr std::array<size_t, 5> imm_size_lut = []()consteval{
    auto ret = decltype(imm_size_lut){};
    ret[BaseImm::Group::None]   = 0;
    ret[BaseImm::Group::S8]     = 1;
    ret[BaseImm::Group::S16]    = 2;
    ret[BaseImm::Group::S32]    = 4;
    ret[BaseImm::Group::S64]    = 8;
    return ret;
}();

BaseReg::BaseReg(Group group) noexcept: Operand(), group{group}{
    is_reg = true;
    size = reg_size_lut[group];
}

BaseMem::BaseMem(Group group) noexcept: Operand(), group{group}{ 
    is_mem = true;
    size = mem_size_lut[group];
}

BaseImm::BaseImm(Group group) noexcept: Operand(), group{group}{ 
    is_imm = true; 
    size = imm_size_lut[group];
}