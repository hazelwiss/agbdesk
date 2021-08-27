#pragma once
#include<common.h>
#include<JIT/base.h>
#include<set>
#include<util/int.h>
#include<optional>
#include<cstring>
#define CREATE_BASIC_OVERLOADS(func)        \
    void func (const GPR&, const GPR&);     \
    void func (const GPR&, const Mem&);     \
    void func (const GPR&, const Imm&);     \
    void func (const Mem&, const GPR&);     \
    void func (const Mem&, const Imm&);     \



namespace x64{
    namespace ErrStrings{
        constexpr char INVOPERANDS[] = "invalid operand combination."; 
        constexpr char INVOPERANSIZES[] = "invalid operand size combination";
    };
    struct GPR;
    struct Mem;
    struct Imm;

    struct SIB{
        SIB() = default;
        SIB(Int<3> base, Int<3> index, Int<2> scale): 
            scale{scale}, index{index}, base{base} {}
        Int<2> scale;
        Int<3> index;
        Int<3> base;
    };

    //  Used for effective addressing
    struct Address{
        Address() = delete;
        Address(const GPR& reg){}
        Address(size_t val){
            dispatch = val;
        }
        Address&& operator+(const GPR& reg);
        Address&& operator+(size_t val);
        Address&& operator*(size_t val);
    protected:
        SIB sib;
        size_t dispatch;
    };

    //  Register Argument
    struct GPR: BaseReg{
        enum class SizePrefixes{
            F16 = 0x66,
            F64 = 0x48
        };
        GPR(BaseReg::Group group, Int<4> regindex) noexcept: 
            BaseReg(group), 
            regindex{.index = (size_t)regindex, .extension = regindex.getBit(3)} 
        {
            switch(group){
            case Group::GPR16: size_prefix = (size_t)SizePrefixes::F16; break;
            case Group::GPR64: size_prefix = (size_t)SizePrefixes::F64; break;
            default:;
            }
        }
        Address operator+(size_t val) const noexcept;
        Address operator+(GPR reg) const noexcept;
        Address operator*(size_t val) const noexcept;
        friend Address operator+(size_t val, const GPR& reg){ }
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
            Int<3> sib_base = 0,
            Int<3> sib_index = 0,
            Int<2> sib_scale = 0
        ) noexcept: BaseMem(group),
            sib_base{sib_base}, sib_index{sib_index}, sib_scale{sib_scale} {} 
    protected:
        size_t sib_base, sib_index, sib_scale;
    };
    //  Constant Argument
    struct Imm: BaseImm{
        Imm(BaseImm::Group group) noexcept: BaseImm(group) {}
    };

    enum class Prefix: uint8_t{ 
        LOCK = 0xF0,    //  lock prefix
    };

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
    };

    namespace Ptr{
        struct Pointer{
            Pointer(BaseMem::Group group): group{group} {}; 
            Mem operator[](Address&&) const noexcept;
        protected:
            BaseMem::Group group;
        };
        extern const Pointer qword;
        extern const Pointer dword;
        extern const Pointer word;
        extern const Pointer byte;    //  unused?
    }

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