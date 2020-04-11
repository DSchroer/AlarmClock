#include "list_menu.hpp"
#include <stdio.h>

void ListMenu::Render(Display &display){
    display.SetCursor(23, 2);
    display.Write(title, 1);
    display.Line(11);

    display.Line(7, 23, 66);

    RenderLine(15, position, display);
    RenderLine(25, position + 1, display);
    RenderLine(35, position + 2, display);
}

void ListMenu::OnButton(uint8_t button){
    if(button == 2 && position < options.Count - 1){
        position++;
    }
    if(button == 1 && position > 0){
        position--;
    }

    if(button == 3){
        options[position].Click();
    }

    if(parent != nullptr && button == 0){
        Manager.MoveTo(parent);
    }
}

void ListMenu::Reset(){
    
}

void ListMenu::RenderLine(uint8_t y, uint8_t renderPos, Display &display) {
    display.SetCursor(8, y);

    if (renderPos >= options.Count) {
        return;
    }

    Option& option = options[renderPos];

    char buffer[6];
    snprintf(buffer, sizeof(buffer), "#%d ", renderPos);
    display.Write(buffer, 1);

    option.Draw(display);
}

void ListMenu::AddOption(Option option) {
    options.Add(option);
}

void ListMenu::SetParent(Menu &parentMenu) {
    parent = &parentMenu;
}
