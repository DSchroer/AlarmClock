
#include "./menu_utils.hpp"

#include <stdio.h>


static const char *months[]{"January",
                            "February",
                            "March",
                            "April",
                            "May",
                            "June",
                            "July",
                            "August",
                            "September",
                            "October",
                            "November",
                            "December"};

static const char *days[]{
    "Sunday ",
    "Monday ",
    "Tuesday ",
    "Wednesday ",
    "Thursday ",
    "Friday ",
    "Saturday "};

uint8_t clamp(uint8_t d, uint8_t min, uint8_t max) {
  const uint8_t t = d < min ? min : d;
  return t > max ? max : t;
}

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
    display.Write(days[clamp(time.day, 1, 8) - 1], 1);

    char dateBuffer[9];
    snprintf(dateBuffer, sizeof(dateBuffer), "%02d 20%02d", time.date, time.year);

    display.SetCursor(1,30);
    display.WriteL(dateBuffer, 3, 1);
    display.Write(months[clamp(time.month, 1, 12)  - 1], 1);

    display.SetCursor(1,40);
    display.WriteL(&dateBuffer[3], 4, 1);
}
