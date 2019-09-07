#include <cstdio>
#include "alarm_edit.hpp"

void AlarmEdit::Render(Display &display) {
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", alarm.hour, alarm.minute);
    display.Write(buffer);


}

void AlarmEdit::OnButton(uint8_t button) {

}
