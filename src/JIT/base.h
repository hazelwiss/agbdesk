#pragma once
#include<common.h>

struct EmitDestination{
    EmitDestination() noexcept = default;
    EmitDestination(uint8_t* data, size_t capacity) noexcept: data{data}, capacity{capacity} {}
    void pushByte(uint8_t byte) noexcept        { *data++ = byte; }
    void pushDByte(uint16_t dbyte) noexcept     { *((uint16_t*&)data)++ = dbyte; }
    void pushQByte(uint32_t qbyte) noexcept     { *((uint32_t*&)data)++ = qbyte; }
    void pushDQByte(uint64_t dqbyte) noexcept   { *((uint64_t*&)data)++ = dqbyte; }
protected:
    uint8_t* data;
    size_t capacity;
    size_t size{0};
};

struct Operand{
    constexpr Operand() noexcept                = default;
    constexpr Operand(const Operand&) noexcept  = default;
    bool isReg() const noexcept{ return is_reg; }
    bool isMem() const noexcept{ return is_mem; }
    bool isImm() const noexcept{ return is_imm; }
    uint8_t getSize() const{ return size; }
    bool operator==(const Operand& other) const{ return size == other.size; }
/*
    Data members.
*/
public:
    uint8_t data[8];
protected:
    bool is_reg{false};
    bool is_mem{false};
    bool is_imm{false};
    uint8_t size{0};
};

struct BaseReg: Operand{
    enum Group{
        None,
        GPR8Lo,
        GPR8Hi,
        GPR16,
        GPR32,
        GPR64,
    };
    BaseReg(Group group) noexcept;
    constexpr Group getGroup() const { return group; }
protected:
    Group group;
};

struct BaseMem: Operand{
    enum Group{
        None,
        S8,
        S16,
        S32,
        S64
    };
    BaseMem(Group type) noexcept;
    constexpr Group getGroup() const { return group; }
protected:
    union{
        uint64_t address64{0};
        uint32_t address32;
        uint16_t address16;
    };
    Group group;
};

struct BaseImm: Operand{
    enum Group{
        None,
        S8,
        S16,
        S32,
        S64
    };
    BaseImm(Group group) noexcept;
    constexpr Group getGroup() const { return group; }
protected:
    Group group;
};
