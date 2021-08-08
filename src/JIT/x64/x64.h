#pragma once
#include<common.h>
#include<JIT/base.h>

struct EmitDestination{};

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
        bool isLocked() const;
        void lock();
        void unlock();
        /*
            Emitter functions.
        */
        /*  
            ALU opererations
        */
        //  ADD
        void eADD(GPR, GPR) const;
        void eADD(GPR, Mem) const;
        void eADD(GPR, Imm) const;
        void eADD(Mem, GPR) const;
        void eADD(Mem, Imm) const;
        /*
            Output operations.
        */
        //  MOV
        void eMOV(GPR, GPR) const;
        void eMOV(GPR, Mem) const;
        void eMOV(GPR, Imm) const;
        void eMOV(Mem, GPR) const;
        void eMOV(Mem, Imm) const;
    protected:
        bool mutlock;
        EmitDestination destination;
    };
    
    struct Assembler: BaseEmitter{

    };
};