#include"x64.h"
#include<stdexcept>
#include<util/bits.h>
#include<stdexcept>

using namespace x64;

Address&& Address::operator+(const GPR& reg){ 
    return std::move(*this); 
}
Address&& Address::operator+(size_t val){ 
    return std::move(*this); 
}
Address&& Address::operator*(size_t val){ 
    return std::move(*this); 
}

namespace x64::Regs{
    const GPR RAX{BaseReg::Group::GPR64, 0};
    const GPR EAX{BaseReg::Group::GPR32, 0};
    const GPR AX{BaseReg::Group::GPR16, 0};

    const GPR RBX{BaseReg::Group::GPR64, 3};
    const GPR EBX{BaseReg::Group::GPR32, 3};
    const GPR EX{BaseReg::Group::GPR16, 3};

    const GPR RCX{BaseReg::Group::GPR64, 1};
    const GPR ECX{BaseReg::Group::GPR32, 1};
    const GPR CX{BaseReg::Group::GPR16, 1};

    const GPR RDX{BaseReg::Group::GPR64, 2};
    const GPR EDX{BaseReg::Group::GPR32, 2};
    const GPR DX{BaseReg::Group::GPR16, 2};

    Address GPR::operator+(size_t val) const noexcept {  }
    Address GPR::operator+(GPR reg) const noexcept {  }
    Address GPR::operator*(size_t val) const noexcept {  }
};

namespace x64::Ptr{
    Mem x64::Ptr::Pointer::operator[](Address&& adr) const noexcept{
        return Mem(group, 1, 1, 1);
    }
    const Pointer qword{BaseMem::S64};
    const Pointer dword{BaseMem::S32};
    const Pointer word{BaseMem::S16};
    const Pointer byte{BaseMem::S8};   
}
struct Opcode{
    constexpr Opcode(uint8_t opc) noexcept: 
        value{opc} {}
    constexpr Opcode(const std::optional<uint8_t>& size_prefix, uint8_t opc) noexcept: size_prefix{size_prefix.has_value()}  {
        if(this->size_prefix){
            value = size_prefix.value() | (opc << 8);
        } else 
            value = opc;
    }
    constexpr uint16_t getValue() const noexcept { return value; }
    void parse(EmitDestination& destination) const noexcept {
        if(size_prefix)
            destination.pushDByte(value); 
        else
            destination.pushByte(value);
    }
protected:
    uint16_t value;
    const bool size_prefix{false};
};

struct ModRM{
    ModRM(size_t rm, size_t reg, size_t mod): byte{(uint8_t)(rm|(reg<<3)|(mod<<6))} {} 
    uint8_t getByte(){ return byte; }
protected:
    uint8_t byte;
};

void AssertOperandSize(const Operand& a, const Operand& b){ if(a!=b) throw std::runtime_error(ErrStrings::INVOPERANSIZES); }

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
void BaseEmitter::eADD(const GPR& a, const GPR& b){
    AssertOperandSize(a, b);
    Opcode(a.getSizePrefix(), 1).parse(destination);
    destination.pushByte(ModRM(a.regindex.index, b.regindex.index, 11).getByte());
}

void BaseEmitter::eADD(const GPR& a, const Mem& b){
    AssertOperandSize(a, b);
    Opcode(a.getSizePrefix(), 3).parse(destination);
    destination.pushByte(ModRM(3,0,0).getByte());
    b.parse(destination);
}

void BaseEmitter::eADD(const GPR& a, const Imm& b){
    AssertOperandSize(a, b);
}

void BaseEmitter::eADD(const Mem& a, const GPR& b){
    AssertOperandSize(a, b);
}

void BaseEmitter::eADD(const Mem& a, const Imm& b){
    AssertOperandSize(a, b);
}

/*
    MOV
*/
