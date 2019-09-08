#include <stdio.h>
#include "alarm_edit.hpp"

void AlarmEdit::Render(Display &display) {

    display.SetCursor(15, 8);

    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", alarm.hour, alarm.minute);
    display.Write(buffer, 2);

    display.SetCursor(3, 30);
    display.Write("M T W T F S S");

    display.SetCursor(3, 40);
    display.Write("X X X X X X X");

    display.Line(15, 23, 23);

    display.Line(48, 23, 24);

    display.Line(3, 38, 5);

    display.Line(15, 38, 5);

    display.Line(27, 38, 5);

    display.Line(39, 38, 5);

    display.Line(51, 38, 5);

    display.Line(63, 38, 5);

    display.Line(75, 38, 5);
}

void AlarmEdit::OnButton(uint8_t button) {

}

void AlarmEdit::Reset() {
    alarm = registry[alarmIndex];
}
