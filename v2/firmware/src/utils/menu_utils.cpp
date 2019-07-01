
#include "./menu_utils.hpp"

#include <stdio.h>

void DrawTime(Display& display, const Time& time) {
    //Top alarm
    display.SetCursor(10,2);
    
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%02d:%02d%02d", time.hours, time.minutes, time.seconds);
    display.WriteL(buffer, 5 , 2);
    display.WriteL(&buffer[5] , 2, 1);

    display.Line(18);

    //Day Display
    display.SetCursor(1,20);
    display.Write("DAY MON YEAR", 1);

}
