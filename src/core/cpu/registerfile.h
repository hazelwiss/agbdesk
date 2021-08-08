#pragma once
#include<common.h>
#include<array>

enum Regs{ 
    R0,     R1,     R2,     R3,
    R4,     R5,     R6,     R7,
    R8,     R9,     R10,    R11,
    R12,    R13,    R14,    R15,
    CPSR,               SPSR_fiq,
    SPSR_svc,           SPSR_abit,
    SPSR_irq,           SPSR_und   
};

struct RegisterFile{
    template<Regs R> uint32_t& get32(){ return registers[(size_t)R]; }
protected:
    std::array<uint32_t,37> registers;
};