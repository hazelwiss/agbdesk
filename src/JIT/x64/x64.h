#pragma once
#include<common.h>
#include<JIT/base.h>
#include<set>
#include<util/int.h>
#include<optional>
#include<cstring>
#include<optional>
#include<stdexcept>
#include<util/bits.h>
#include"errstring.h"

#define CREATE_BASIC_OVERLOADS(func)        \
    void func (RefReg, RefReg);                   \
    void func (RefReg, RefMem);            \
    void func (RefReg, RefImm);            \
    void func (RefMem, RefReg);            \
    void func (RefMem, RefImm);     \

namespace x64{
    struct GPR;
    struct Mem;
    struct Imm;
    using RefReg = const GPR&;
    using RefMem = const Mem&;
    using RefImm = const Imm&;

    struct SIB{
        SIB() = default;
        SIB(RefReg base, RefReg index, Int<2> scale): 
            scale{scale}, index{&index}, base{&base} {}
        void setScale(Int<2> scale) noexcept    { this->scale = scale; }
        void setIndex(const GPR& reg) noexcept  { this->index = &reg; }
        void setBase(const GPR& reg) noexcept   { this->base = &reg; }
        size_t getScale() const noexcept        { return scale; }
        const GPR& getIndex() const { if(!index) throw std::runtime_error(ErrStrings::INVSIB); return *index; }
        const GPR& getBase() const  { if(!base) throw std::runtime_error(ErrStrings::INVSIB); return *base; }
    protected:
        Int<2> scale;
        const GPR* index{nullptr};
        const GPR* base{nullptr};
    };

    //  Used for effective addressing
    enum class DispSize{ i8, i32 };
    struct Disp{
        constexpr Disp() = default;
        constexpr Disp(int64_t d) noexcept: size{(d <= INT8_MAX && d >= INT8_MIN) ? DispSize::i8 : DispSize::i32}, disp{d} {}
        constexpr Disp& operator+=(const Disp& disp){ return *this = Disp(this->disp + disp.disp); }
        constexpr Disp& operator-=(const Disp& disp){ return *this = Disp(this->disp - disp.disp); }
        constexpr int64_t getDisp() const noexcept { return size == DispSize::i8 ? (int8_t)disp : (int32_t)disp; }
        DispSize size{DispSize::i8};
    protected:
        int64_t disp{0};
    };

    struct Address{
        Address() = delete;
        Address(RefReg RefReg) noexcept;
        Address(RefReg RefReg, size_t scale) noexcept;
        Address(size_t val) noexcept;
        Address&& operator+(RefReg RefReg);
        Address&& operator+(Disp val);
        Address&& operator-(Disp val);
        Address&& operator*(size_t val);
        const SIB& getSIB() const noexcept { return sib; }
        const size_t getDispatch() const noexcept { return dispatch.getDisp(); }
        friend Address&& operator+(RefReg RefReg, Address&& adr);
        friend Address&& operator+(size_t val, Address&& adr);
        bool hasDisp32() const noexcept { return hasDisp() && (dispatch.size == DispSize::i32); }
        bool hasDisp8() const noexcept  { return hasDisp() && (dispatch.size == DispSize::i8); }
        bool hasDisp() const noexcept   { return has_disp; }
        bool hasScale() const noexcept  { return has_sib_scale; }
        bool hasBase() const noexcept   { return has_sib_base; }
        bool hasIndex() const noexcept  { return has_sib_index; }
        bool hasSIB() const noexcept { return hasScale() && hasBase() && hasIndex(); }
    protected:
        SIB sib;
        Disp dispatch;
        bool has_disp{false}, has_sib_scale{false}, has_sib_base{false}, has_sib_index{false};
    };

    namespace Ptr{
        struct Pointer{
            Pointer(BaseMem::Group group): group{group} {}; 
            Mem operator[](Address&&) const noexcept;
        protected:
            BaseMem::Group group;
        };
        extern const Pointer QWORD;
        extern const Pointer DWORD;
        extern const Pointer WORD;
        extern const Pointer BYTE;    //  unused?
    }

    namespace Regs{
        extern const GPR RAX;
        extern const GPR EAX;
        extern const GPR AX;

        extern const GPR RBX;
        extern const GPR EBX;
        extern const GPR EX;

        extern const GPR RCX;
        extern const GPR ECX;
        extern const GPR CX;

        extern const GPR RDX;
        extern const GPR EDX;
        extern const GPR DX;

        extern const GPR RDI;
        extern const GPR EDI;
        extern const GPR DI;
    };

    //  RefRegister Argument
    struct GPR: BaseReg{
        enum class SizePrefixes{
            F16 = 0x66,
            F64 = 0x48
        };
        GPR(BaseReg::Group group, Int<4> RefRegindex) noexcept: 
            BaseReg(group), 
            regindex{.index = (size_t)RefRegindex, .extension = RefRegindex.getBit(3)} 
        {
            switch(group){
            case Group::GPR16: size_prefix = (size_t)SizePrefixes::F16; break;
            case Group::GPR64: size_prefix = (size_t)SizePrefixes::F64; break;
            default:;
            }
        }
        Address operator+(size_t val) const noexcept;
        Address operator-(size_t val) const noexcept;
        Address operator+(RefReg RefReg) const noexcept;
        Address operator*(size_t val) const noexcept;
        friend Address operator+(size_t val, RefReg RefReg) noexcept;
        size_t getValue() const noexcept { size_t val; std::memcpy(&val, data, getSize()); return val; }
        const std::optional<uint8_t>& getSizePrefix() const noexcept { return size_prefix; }
        struct{
            Int<3> index;
            bool extension;
        } const regindex;
    protected:
        std::optional<uint8_t> size_prefix;
    };
    //  Memory Argument 
    struct Mem: BaseMem{
        Mem(
            BaseMem::Group group, 
            const Address& adr
        ) noexcept: BaseMem(group), adr{adr} {} 
        Address adr;
    };
    //  Constant Argument
    struct Imm: BaseImm{
        Imm(BaseImm::Group group) noexcept: BaseImm(group) {}
    };

    enum class Prefix: uint8_t{ 
        LOCK = 0xF0,    //  lock prefix
    };

    struct BaseEmitter{
        void setEmitDest(uint8_t* data, size_t capacity) { destination = EmitDestination(data, capacity); };
        template<Prefix fix>
        constexpr bool hasPrefix() const noexcept { return std::find(prefixes.begin(), prefixes.end(), fix) != prefixes.end(); }
        template<Prefix fix>
        constexpr void enablePrefix() noexcept { prefixes.insert(fix); }
        template<Prefix fix>
        constexpr void disablePrefix() noexcept { prefixes.erase(fix); }
        /*
            Emitter functions.
        */
        void emitPrefixes() noexcept;

        /*  
            ALU opererations
        */
        //  ADD
        CREATE_BASIC_OVERLOADS(eADD);
        /*
            Output operations.
        */
        //  MOV
        CREATE_BASIC_OVERLOADS(eMOV);
    protected:
        std::set<Prefix> prefixes;
        EmitDestination destination;
    };
    
    struct Assembler: BaseEmitter{
        Assembler(uint8_t* data, size_t capacity) noexcept: BaseEmitter() { setEmitDest(data, capacity); }
    };
};