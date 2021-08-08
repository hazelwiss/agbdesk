/*

*/

#pragma once
#include<agbdesk.h>
#include<util/int.h>

namespace ARMInstrDef{
    using RetType = InstrFuncRetType;
    /*
        Branch Exchange.
    */
    RetType iBX(AGBDesk& emu){}
    /*
        Branch, Branch Link.
    */
    template<bool L>
    RetType iB(AGBDesk& emu){}
    /*
        Data processing.
    */
    template<bool I, uint8_t OpCode, bool S, Regs Rn, Regs Rd, Int<12> Operand_2>
    RetType iDP(AGBDesk& emu){}
    /*
        Multiply, Multiply-Accumulate.
    */
    template<bool A, bool S, Regs Rd, Regs Rn, Regs Rs, Regs Rm>
    RetType iM(AGBDesk& emu){}
    /*
        Multiply Long, Multiply-Accumulate Long
    */
    template<bool U, bool A, bool S, Regs RdHi, Regs RdLo, Regs Rs, Regs Rm>
    RetType iML(AGBDesk& emu){}
    /*
        Single Data Transfer
    */
    template<bool I, bool P, bool U, bool B, bool W, bool L, bool Rn, bool Rd, Int<12> offset>
    RetType iSDT(AGBDesk& emu){}
    /*
        Block Data Transfer
    */
    template<bool P, bool U, bool S, bool W, bool L, Regs Rn, uint16_t Register_List>
    RetType iBDT(AGBDesk& emu){}
    /*
        Single Data Swap
    */
    template<bool B, Regs Rn, Regs Rd, Regs Rm> 
    RetType iSDS(){}
    /*
        Software Interrupt.
    */
    RetType iSWI(AGBDesk& emu){}
};
