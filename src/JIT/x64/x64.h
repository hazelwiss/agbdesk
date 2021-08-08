#pragma once
#include<common.h>
#include<JIT/base.h>

namespace x64{
    //  Register Argument
    struct GPR: BaseReg{
        GPR(BaseReg::Group type) noexcept: BaseReg(type) {}
    };
    //  Memory Argument 
    struct Mem: BaseMem{
        Mem(BaseMem::Group type) noexcept: BaseMem(type) {}
    };
    //  Constant Argument
    struct Imm: BaseImm{
        Imm(BaseImm::Group type) noexcept: BaseImm(type) {}
    };

    struct BaseEmitter{
        void setEmitDest(uint8_t* data, size_t capacity) { destination = EmitDestination(data, capacity); };
        constexpr bool isLocked() const { return mutlock; }
        void lock()     { mutlock = true; }
        void unlock()   { mutlock = false; }
        /*
            Emitter functions.
        */
        /*  
            ALU opererations
        */
        //  ADD
        void eADD(GPR, GPR);
        void eADD(GPR, Mem);
        void eADD(GPR, Imm);
        void eADD(Mem, GPR);
        void eADD(Mem, Imm);
        /*
            Output operations.
        */
        //  MOV
        void eMOV(GPR, GPR);
        void eMOV(GPR, Mem);
        void eMOV(GPR, Imm);
        void eMOV(Mem, GPR);
        void eMOV(Mem, Imm);
    protected:
        bool mutlock;
        EmitDestination destination;
    };
    
    struct Assembler: BaseEmitter{
        Assembler(uint8_t* data, size_t capacity) noexcept: BaseEmitter() { setEmitDest(data, capacity); }
    };
};