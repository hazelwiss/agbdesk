#include"base.h"

BaseReg::BaseReg(Group group) noexcept: group{group}, Operand(){
    is_reg = true;
    switch(group)
    {
    case Group::GPR8Lo:
    case Group::GPR8Hi:
        size = 1;
        break;
    case Group::GPR16:
        size = 2;
        break;
    case Group::GPR32:
        size = 4;
        break;
    case Group::GPR64:
        size = 8;
        break;
    }
}

BaseMem::BaseMem(Group type) noexcept: group{group}, Operand(){ 
    is_mem = true;
}

BaseImm::BaseImm(Group group) noexcept: group{group}, Operand(){ 
    is_imm = true; 
}