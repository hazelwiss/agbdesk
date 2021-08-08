#include"agbdesk.h"
#include<memory>
#include<core/cpu/instructions.h>

AGBDesk::AGBDesk(){
    //this->memory = std::vector<uint8_t>(GBAInfo::MEMORY_SIZE,0);
    ARMInstruction instr{*this, 0b11111101111111111111111111111111};
    //instr.execute();
}