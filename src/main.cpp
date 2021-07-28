#include<imgui.h>
#include<imgui-SFML.h>
#include<SFML/Graphics/CircleShape.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/Window/Event.hpp>
#include<iostream>
#include"common.h"
#include"agbdesk.h"
#include<terminal/agbterm.h>

int main(){
    AGBTerm::run("help");
    AGBTerm::run("2");
    return 1;
    AGBDesk gba;
    return 1;
    sf::RenderWindow win{sf::VideoMode(640, 480), "ImGui+SFML"};
    win.setFramerateLimit(60);
    ImGui::SFML::Init(win);
    sf::Clock delta_clk;
    while(win.isOpen()){
        sf::Event event;
        while(win.pollEvent(event)){
            ImGui::SFML::ProcessEvent(event);
            if(event.type == sf::Event::Closed)
                win.close();
        }
        ImGui::SFML::Update(win, delta_clk.restart());
        if(ImGui::BeginMainMenuBar()){
            ImGui::EndMainMenuBar();
        }
        if(ImGui::Begin("window")){
            ImGui::Text("hello!");
            ImGui::End();
        }
        win.clear();
        ImGui::SFML::Render(win);
        win.display();
    }
}