#pragma once
#include<common.h>

struct Operand{
    constexpr Operand() noexcept                = default;
    constexpr Operand(const Operand&) noexcept  = default;
    bool isReg() const noexcept{ return is_reg; }
    bool isMem() const noexcept{ return is_mem; }
    bool isImm() const noexcept{ return is_imm; }
    uint8_t size() const{}
    bool operator==(const Operand& other){ return size() == other.size(); }
/*
    Data members.
*/
public:
    uint8_t data[8];
protected:
    bool is_reg{false};
    bool is_mem{false};
    bool is_imm{false};
    uint8_t size{0};
};

struct BaseReg: Operand{
    enum Group{
        None,
        GPR8Lo,
        GPR8Hi,
        GPR16,
        GPR32,
        GPR64,
    };
    BaseReg(Group group);
    Group getGroup() { return group; }
protected:
    Group group{None};
};

struct BaseMem: Operand{
    enum Group{
        None,
        S8,
        S16,
        S32,
        S64
    };
    BaseMem(Group type);
    Group getGroup() { return group; }
protected:
    Group group{None};
};

struct BaseImm: Operand{
    enum Group{
        None,
        S8,
        S16,
        S32,
        S64
    };
    BaseImm(Group group);
    Group getGroup() { return group; }
protected:
    Group group{None};
};

