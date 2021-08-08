#include"instructiontable.h"
#include<util/staticeval.h>

struct ARMInstructionBits{
    constexpr ARMInstructionBits(uint16_t mask, uint16_t opcode): mask{mask}, opcode{opcode} {}
    uint16_t mask;
    uint16_t opcode;
};

constexpr ARMInstructionBits operator"" _ib(const char* str, size_t s){
    ARMInstructionBits ret{0,0};
    for(size_t i = 0; i < s; ++i){
        if(str[i]!='x')
            ret.mask |= 0x800 >> i;
    }
    for(size_t i = 0; i < s; ++i){
        if(str[i]!='x')
            ret.opcode |= (0x800*(str[i]-'0')) >> i;
    }
    return ret;
}

//                                        27-20   7-4
constexpr ARMInstructionBits dp_ib     = "001xxxxxxxxx"_ib;
constexpr ARMInstructionBits m_ib      = "000000xx1001"_ib;
constexpr ARMInstructionBits ml_ib     = "00001xxx1001"_ib;
constexpr ARMInstructionBits sds_ib    = "00010x001001"_ib;
constexpr ARMInstructionBits bx_ib     = "000100100001"_ib;
constexpr ARMInstructionBits hdtro_ib  = "000xx0xx1xx1"_ib;
constexpr ARMInstructionBits hdtio_ib  = "000xx1xx1xx1"_ib;
constexpr ARMInstructionBits sdt_ib    = "01xxxxxxxxxx"_ib;
constexpr ARMInstructionBits undef_ib  = "011xxxxxxxx1"_ib;
constexpr ARMInstructionBits bdt_ib    = "100xxxxxxxxx"_ib;
constexpr ARMInstructionBits b_ib      = "110xxxxxxxxx"_ib;
constexpr ARMInstructionBits swi_ib    = "1111xxxxxxxx"_ib;

#include"arminstr.h"  //  includes all ARM instruction defintions.

const ARMInstrTable::ARMTable ARMInstrTable::ARMLUT = []()consteval->ARMInstrTable::ARMTable{ 
    ARMInstrTable::ARMTable table;
    auto lambda = [&](const uint16_t opc){ 
        if((opc&dp_ib.mask) == dp_ib.opcode){
            table[opc].type = InstructionTypes::DATA_PROCESSING;
            table[opc].func = ARMInstrDef::iDP<>;
        } else if((opc&m_ib.mask) == m_ib.opcode){
            table[opc].type = InstructionTypes::MULTIPLY;
            table[opc].func = 0;
        } else if((opc&ml_ib.mask) == ml_ib.opcode){
            table[opc].type = InstructionTypes::MULTIPLY_LONG;
            table[opc].func = 0;
        } else if((opc&sds_ib.mask) == sds_ib.opcode){
            table[opc].type = InstructionTypes::SINGLE_DATA_SWAP;
            table[opc].func = 0;
        } else if((opc&bx_ib.mask) == bx_ib.opcode){
            table[opc].type = InstructionTypes::BRANCH_EXCHANGE;
            table[opc].func = ARMInstrDef::iBX;
        } else if((opc&hdtro_ib.mask) == hdtro_ib.opcode){
            table[opc].type = InstructionTypes::HALFWORD_DATA_TRANSFER_REG_OFFSET;
            table[opc].func = 0;
        } else if((opc&hdtio_ib.mask) == hdtio_ib.opcode){
            table[opc].type = InstructionTypes::HALFWORD_DATA_TRANSFER_IMM_OFFSET;
            table[opc].func = 0;
        } else if((opc&sdt_ib.mask) == sdt_ib.opcode){
            table[opc].type = InstructionTypes::SINGLE_DATA_TRANSFER;
            table[opc].func = 0;
        } else if((opc&bdt_ib.mask) == bdt_ib.opcode){
            table[opc].type = InstructionTypes::BLOCK_DATA_TRANSFER;
            table[opc].func = 0;
        } else if((opc&b_ib.mask) == b_ib.opcode){
            table[opc].type = InstructionTypes::BRANCH;
            table[opc].func = 0;
        } else if((opc&swi_ib.mask) == swi_ib.opcode){
            table[opc].type = InstructionTypes::SOFTWARE_INTERRUPT;
            table[opc].func = ARMInstrDef::iSWI;
        } else{
            table[opc].type = InstructionTypes::UNDEFINED;
            table[opc].func = 0;
        }
    };
    StaticForLoop<size_t, 0, BitsMax<12>::max()>{lambda}; 
    return table;
}();