#include "menu_manager.hpp"
#include "../../drivers/include/display.hpp"

void MenuManager::MoveTo(Menu& menu){
    menu.Reset();
    current = &menu;
}

void MenuManager::Update(){
    for(uint8_t btnIndex = 0; btnIndex < 4; btnIndex++){
        if(buttons.Pressed(btnIndex)){
            current->OnButton(btnIndex);
        }
    }

    current->Update();
}

void MenuManager::Render(Display& display){
    display.SetCursor(0,0);
    current->Render(display);
}