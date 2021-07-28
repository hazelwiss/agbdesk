#include<imgui.h>
#include<imgui-SFML.h>
#include<SFML/Graphics/CircleShape.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/Window/Event.hpp>
#include<iostream>
#include<terminal/agbterm.h>
#include<visual/visual.h>
#include"common.h"
#include"agbdesk.h"
#include<thread>

int main(){
    Visual::init();
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 1;
}