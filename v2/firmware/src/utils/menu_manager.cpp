#include "menu_manager.hpp"
#include <display.hpp>

void MenuManager::MoveTo(Menu& menu){
    menu.Reset();
    current = &menu;
}

void MenuManager::Update(){
    current->Update();
}

void MenuManager::Render(Display& display){
    current->Render(display);
}