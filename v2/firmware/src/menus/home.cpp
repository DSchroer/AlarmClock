#include "home.hpp"
#include <stdio.h>
#include <string.h>

#include "../utils/menu_utils.hpp"

void Spiner(Display& display){
    static int state = 0;

    state = (state + 1) % 4;
    switch (state)
    {
    case 0:
        display.Write('\\');
        break;
    case 1:
        display.Write('|');
        break;
    case 2:
        display.Write('/');
        break;
    case 3:
        display.Write('-');
        break;
    
    default:
        break;
    }
}

void Home::Render(Display& display){

    const auto time = _clock.time;

    DrawTime(display, time);
    
    // display.SetCursor(1,40);
    // Spiner(display);
    // display.Write("Alarm:", 1);
}

void Home::OnButton(uint8_t button){
    Manager.MoveTo(_main_menu);
}