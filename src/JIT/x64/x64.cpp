#include"x64.h"
#include<tuple>

using namespace x64;


void emitOpcode(EmitDestination& dest, uint8_t opc) noexcept {
    dest.pushByte(opc);;
}

template<uint8_t opcode0>
void emitOpcode(EmitDestination& dest, 
    const std::optional<uint8_t>& size_prefix) noexcept {
    uint32_t opc = opcode0;
    if(size_prefix){
        dest.pushDByte(size_prefix.value() | ((opc) << 8)); 
    } else
        dest.pushByte(opc);
}

template<uint8_t opcode0, uint8_t opcode1>
void emitOpcode(EmitDestination& dest, 
    const std::optional<uint8_t>& size_prefix) noexcept {
    uint32_t opc = opcode0 | (opcode1 << 8);
    if(size_prefix){
        dest.pushDByte(size_prefix.value() | ((opc) << 8)); 
    } else
        dest.pushDByte(opc);
}

template<uint8_t opcode0, uint8_t opcode1, uint8_t opcode2>
void emitOpcode(EmitDestination& dest, 
    const std::optional<uint8_t>& size_prefix) noexcept {
    uint32_t opc = opcode0 | (opcode1 << 8) | (opcode2 << 16);
    if(size_prefix){
        dest.pushDByte(size_prefix.value() | ((opc) << 8));
        dest.pushDByte(opc >> 8); 
    } else{
        dest.pushDByte(opc);
        dest.pushByte(opc >> 16);
    }
}

enum class MOD: size_t{
    REGISTER_ADDRESSING = 0b11,
    INDIRECT_ADDRESSING = 0b00,
    DISP8 = 0b01,
    DISP32 = 0b10
};

void emitModRM(EmitDestination& dest, RefReg rm, RefReg reg, MOD mod)
    { dest.pushByte((uint8_t)(rm.regindex.index|(reg.regindex.index<<3)|((size_t)mod<<6))); } 

void emitSIB(EmitDestination& dest, const SIB& sib){ 
    dest.pushByte(sib.getBase().regindex.index  | 
        (sib.getIndex().regindex.index << 3)    | 
        (sib.getBase().regindex.index << 6)); 
}

void emitModSIBDisp(EmitDestination& dest, RefMem mem, RefReg reg) {
    if(!mem.adr.hasSIB() && !mem.adr.hasDisp()){
        emitModRM(dest, mem.adr.getSIB().getBase(), reg, MOD::INDIRECT_ADDRESSING);
    } else if(mem.adr.hasDisp()){
        if(mem.adr.hasDisp32()){
            emitModRM(dest, mem.adr.getSIB().getBase(), reg, MOD::DISP32);
            dest.pushQByte(mem.adr.getDispatch());
        } else{
            emitModRM(dest, mem.adr.getSIB().getBase(), reg, MOD::DISP8);
            dest.pushByte(mem.adr.getDispatch());
        }

    }
    //emitSIB(dest, mem.adr.getSIB());
}

void assertOperandSize(const Operand& a, const Operand& b)
    { if(a!=b) throw std::runtime_error(ErrStrings::INVOPERANSIZES); }

/*
    Emitter functions
*/
void BaseEmitter::emitPrefixes() noexcept {
    for(const auto& prefix: prefixes)
        destination.pushByte((uint8_t)prefix);
}

/*
    ADD
*/
void BaseEmitter::eADD(RefReg a, RefReg b){
    assertOperandSize(a, b);
    emitOpcode<1>(destination, a.getSizePrefix());
    emitModRM(destination, a, b, MOD::INDIRECT_ADDRESSING);
}

void BaseEmitter::eADD(RefReg a, RefMem b){
    assertOperandSize(a, b);
    emitOpcode<3>(destination, a.getSizePrefix());
    emitModSIBDisp(destination, b, a);
}

void BaseEmitter::eADD(RefReg a, RefImm b){
    assertOperandSize(a, b);
}

void BaseEmitter::eADD(RefMem a, RefReg b){
    assertOperandSize(a, b);
}

void BaseEmitter::eADD(RefMem a, RefImm b){
    assertOperandSize(a, b);
}

/*
    MOV
*/
