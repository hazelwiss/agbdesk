#pragma once
#include<vector>
#include"cpu/registerfile.h"
#include"common.h"



struct AGBDesk{
    AGBDesk();
    std::vector<uint8_t> memory;
    RegisterFile regs;
};