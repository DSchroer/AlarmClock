#include "main_menu.hpp"
#include <stdio.h>
#include <string.h>

void MainMenu::Render(Display& display){

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

    display.SetCursor(1,35);
    display.Write("Alarm:", 1);
}