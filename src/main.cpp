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

int main(){
    AGBDesk gba{};
    return 1;
    Visual::init();
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 1;
}