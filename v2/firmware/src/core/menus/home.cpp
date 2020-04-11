#include <stdio.h>
#include "home.hpp"

#include "../utils/menu_utils.hpp"

void Spiner(Display &display) {
    static int state = 0;

    state = (state + 1) % 4;
    switch (state) {
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

void Home::Render(Display &display) {
    const auto time = _clock.time;

    DrawTime(display, time);

    display.SetCursor(78, 40);
    Spiner(display);
}

void Home::OnButton(uint8_t button) {
    if(button != 0){
        Manager.MoveTo(_main_menu);
    }
}