#include"x64.h"
#include<stdexcept>

using namespace x64;

namespace ErrStrings{
    const char INVOPERANDS[] = "invalid operand combination."; 
    const char INVOPERANSIZES[] = "invalid operand size combination";
};

/*
    Emitter functions
*/
/*
    ADD
*/
void BaseEmitter::eADD(GPR a, GPR b){
    if(a != b)
        std::runtime_error(ErrStrings::INVOPERANDS);
    destination.pushByte(0x04);
    destination.pushByte(0x11);
    destination.pushByte(0x04);
    destination.pushByte(0x22);
}

void BaseEmitter::eADD(GPR a, Mem b){
    if(a.getSize() != b.getSize())
        std::runtime_error(ErrStrings::INVOPERANSIZES);
}

void BaseEmitter::eADD(GPR a, Imm b){
    if(a.getSize() != b.getSize())
        std::runtime_error(ErrStrings::INVOPERANSIZES);
}

void BaseEmitter::eADD(Mem a, GPR b){
    if(a.getSize() != b.getSize())
        std::runtime_error(ErrStrings::INVOPERANSIZES);
}

void BaseEmitter::eADD(Mem a, Imm b){
    if(a.getSize() != b.getSize())
        std::runtime_error(ErrStrings::INVOPERANSIZES);
}

/*
    MOV
*/
