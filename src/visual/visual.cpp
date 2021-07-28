#include"visual.h"
#include<imgui.h>
#include<imgui-SFML.h>
#include<SFML/Graphics/CircleShape.hpp>
#include<SFML/Graphics/RenderWindow.hpp>
#include<SFML/System/Clock.hpp>
#include<SFML/Window/Event.hpp>
#include<iostream>
#include<thread>
#include<terminal/agbterm.h>

struct ThreadContext{
    sf::RenderWindow win{sf::VideoMode(1920, 1080), "ImGui+SFML"};
};

std::thread thread;
bool open_terminal      = false;

void renderTerminal(ThreadContext& context){
    //  Renders a GUI of the AGBTerminal
    if(ImGui::Begin("Terminal", &open_terminal)){
        if(ImGui::BeginChild("TextBox",{0,-25}, true)){
            ImGui::TextWrapped(AGBTerm::cout().c_str());
            ImGui::EndChild();
        }
        std::array<char, 255> buf{0};
        if(ImGui::InputText("input", buf.begin(), buf.size(), 
            ImGuiInputTextFlags_EnterReturnsTrue))
        {
            AGBTerm::cin(buf.data());
            AGBTerm::run(buf.data());
        }
        ImGui::End();
    }
}

void threadInit(ThreadContext& context){
    context.win.setFramerateLimit(60);
    ImGui::SFML::Init(context.win);
}

void threadLoop(ThreadContext& context){
    context.win.setFramerateLimit(60);
    ImGui::SFML::Init(context.win);
    sf::Clock deltaclk;
    while(context.win.isOpen()){
        sf::Event event;
        while(context.win.pollEvent(event)){
            ImGui::SFML::ProcessEvent(event);
            if(event.type == sf::Event::Closed)
                context.win.close();
        }
        ImGui::SFML::Update(context.win, deltaclk.restart());
        if(ImGui::BeginMainMenuBar()){
            if(ImGui::BeginMenu("Debug")){
                if(ImGui::MenuItem("Terminal", "", &open_terminal, true)){

                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
        if(ImGui::Begin("Window")){
            if(open_terminal)
                renderTerminal(context);
            ImGui::End();
        }
        context.win.clear(sf::Color::Black);
        ImGui::SFML::Render(context.win);
        context.win.display();
    }
}

void threadEnd(ThreadContext& context){
    ImGui::SFML::Shutdown();
}

void threadCall(){
    ThreadContext context;
    threadInit(context);
    threadLoop(context);
    threadEnd(context);
}

void Visual::init(){
    thread = std::thread{threadCall};
}