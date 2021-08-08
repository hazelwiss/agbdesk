#pragma once
#include<common.h>
#include<agbdesk.h>
#include<array>
#include<util/bits.h>

enum class InstructionTypes{
    DATA_PROCESSING = 0,
    MULTIPLY,
    MULTIPLY_LONG,
    SINGLE_DATA_SWAP,
    BRANCH_EXCHANGE,
    HALFWORD_DATA_TRANSFER_REG_OFFSET,
    HALFWORD_DATA_TRANSFER_IMM_OFFSET,
    SINGLE_DATA_TRANSFER,
    UNDEFINED,
    BLOCK_DATA_TRANSFER,
    BRANCH,
    SOFTWARE_INTERRUPT,
    NUM_INSTR
};

using InstrFuncRetType = void;
using ARMInstrFunc = InstrFuncRetType(AGBDesk&);

struct ARMInstrEntry{
    InstructionTypes type{InstructionTypes::UNDEFINED};
    ARMInstrFunc* func{0};
};

namespace ARMInstrTable{
    inline constexpr uint16_t MAX_POSSIBLE_OPCODE_COMBINATIONS = USHRT_MAX;
    using ARMTable = std::array<ARMInstrEntry, BitsMax<12>::max()>;
    extern const ARMTable ARMLUT;
};