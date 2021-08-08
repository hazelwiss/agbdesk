#pragma once
#include<core/cpu/instructiondefs/instructiontable.h>

/*

*/
struct ARMInstructionDecode{
    explicit ARMInstructionDecode(uint32_t instr);
    InstructionTypes getType(){ return entry.type; }
    ARMInstrFunc* getFunc(){ return entry.func; }
    uint16_t getIndex(){ return opc; }
protected:
    ARMInstrEntry entry;
    uint16_t opc;
};

struct THUMBInstructionDecode{};

struct ARMInstruction{
    ARMInstruction() = delete;
    ARMInstruction(AGBDesk& emu, uint32_t opc): decode{opc}, emu{&emu} {};
    void execute(){ decode.getFunc()(*emu); }
protected:
    ARMInstructionDecode decode;
    AGBDesk* emu;   //  not an l-value reference to allow the use of assignment operators.
};

struct THUMBInstruction{};

