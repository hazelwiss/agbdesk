#include"instructions.h"
#include<common.h>

struct InstructionIndexer{
    //  for ARM mode
    explicit InstructionIndexer(uint32_t opc){ index = ((opc>>16)&0xFFF0) | ((opc>>4)&0x0F); } 
    //  for THUMB mode
    //  explicit InstructionIndexer(uint16_t opc);
    uint16_t get(){ return index; }
protected:
    uint16_t index;
};

ARMInstructionDecode::ARMInstructionDecode(uint32_t instr){
    this->opc = InstructionIndexer(instr).get();
    this->entry = ARMInstrTable::ARMLUT[opc];
}