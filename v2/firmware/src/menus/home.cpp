#include "home.hpp"
#include <stdio.h>
#include <string.h>

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

    //Top alarm
    display.SetCursor(10,2);
    
    char buffer[8];
    snprintf(buffer, sizeof(buffer), "%02d:%02d%02d", time.hours, time.minutes, time.seconds);
    display.WriteL(buffer, 5 , 2);
    display.WriteL(&buffer[5] , 2, 1);

    display.Line(18);

    //Day Display
    display.SetCursor(1,20);
    display.Write("DAY MON YEAR", 1);

    display.SetCursor(1,40);
    Spiner(display);
    // display.Write("Alarm:", 1);
}

void Home::OnButton(uint8_t button){
}