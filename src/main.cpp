/*

*/

#include<imgui.h>
#include<imgui-SFML.h>
#include<SFML/Graphics/CircleShape.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/Window/Event.hpp>
#include<iostream>
#include<frontend/terminal/agbterm.h>
#include<frontend/visual/visual.h>
#include"common.h"
#include"agbdesk.h"
#include<thread>
#include<JIT/x64/x64.h>

int main(){
    std::array<uint8_t, 255> test{0};
    x64::Assembler emitter{test.data(), test.size()};
    auto r2 = x64::Regs::EDX;
    emitter.eADD(r2, x64::Ptr::dword[x64::Regs::RBX+1000]);
    int x = 0;



    return 1;
    AGBDesk gba{};
    return 1;
    Visual::init();
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 1;
}