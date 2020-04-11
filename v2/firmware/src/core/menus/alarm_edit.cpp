#include <stdio.h>
#include <utils/menu_utils.hpp>
#include "alarm_edit.hpp"

void AlarmEdit::Render(Display &display) {

    display.SetCursor(15, 8);

    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", alarm.hour, alarm.minute);
    display.Write(buffer, 2);

    display.SetCursor(3, 30);
    display.Write("M T W T F S S");

    display.SetCursor(3, 40);
    char buffer2[14];
    snprintf(buffer2, sizeof(buffer2), "%c %c %c %c %c %c %c",
             isDay(AlarmDay::Monday) ? 'X' : ' ',
             isDay(AlarmDay::Tuesday) ? 'X' : ' ',
             isDay(AlarmDay::Wednesday) ? 'X' : ' ',
             isDay(AlarmDay::Thursday) ? 'X' : ' ',
             isDay(AlarmDay::Friday) ? 'X' : ' ',
             isDay(AlarmDay::Saturday) ? 'X' : ' ',
             isDay(AlarmDay::Sunday) ? 'X' : ' '
    );
    display.Write(buffer2);

    switch (state) {
        case EditState::Hours:
            display.Line(15, 23, 23);
            break;
        case EditState::Minutes:
            display.Line(48, 23, 24);
            break;
        case EditState::DayMonday:
            display.Line(3, 38, 5);
            break;
        case EditState::DayTuesday:
            display.Line(15, 38, 5);
            break;
        case EditState::DayWednesday:
            display.Line(27, 38, 5);
            break;
        case EditState::DayThursday:
            display.Line(39, 38, 5);
            break;
        case EditState::DayFriday:
            display.Line(51, 38, 5);
            break;
        case EditState::DaySaturday:
            display.Line(63, 38, 5);
            break;
        case EditState::DaySunday:
            display.Line(75, 38, 5);
            break;
        case EditState::Confirm:
            DrawConfirm(display);
            break;
    }
}

void AlarmEdit::OnButton(uint8_t button) {
    if (button == 0) {
        if (state != EditState::Hours) {
            state = state--;
        }
    }
    if (button == 3) {
        if (state != EditState::Confirm) {
            state = state++;
        }
    }

    if (button == 1) {
        switch (state) {
            case EditState::Hours:
                alarm.hour = (alarm.hour + 1) % 24;
                break;
            case EditState::Minutes:
                alarm.minute = (alarm.minute + 1) % 60;
                break;
            case EditState::DayMonday:
                toggleDay(AlarmDay::Monday);
                break;
            case EditState::DayTuesday:
                toggleDay(AlarmDay::Tuesday);
                break;
            case EditState::DayWednesday:
                toggleDay(AlarmDay::Wednesday);
                break;
            case EditState::DayThursday:
                toggleDay(AlarmDay::Thursday);
                break;
            case EditState::DayFriday:
                toggleDay(AlarmDay::Friday);
                break;
            case EditState::DaySaturday:
                toggleDay(AlarmDay::Saturday);
                break;
            case EditState::DaySunday:
                toggleDay(AlarmDay::Sunday);
                break;
            case EditState::Confirm:
                registry[alarmIndex] = alarm;
                Manager.MoveTo(*menu);
                break;
        }
    }

    if (button == 2) {
        switch (state) {
            case EditState::Hours:
                if (alarm.hour == 0) {
                    alarm.hour = 23;
                } else {
                    alarm.hour = alarm.hour - 1;
                }
                break;
            case EditState::Minutes:
                if (alarm.minute == 0) {
                    alarm.minute = 59;
                } else {
                    alarm.minute = alarm.minute - 1;
                }
                break;
            case EditState::DayMonday:
                toggleDay(AlarmDay::Monday);
                break;
            case EditState::DayTuesday:
                toggleDay(AlarmDay::Tuesday);
                break;
            case EditState::DayWednesday:
                toggleDay(AlarmDay::Wednesday);
                break;
            case EditState::DayThursday:
                toggleDay(AlarmDay::Thursday);
                break;
            case EditState::DayFriday:
                toggleDay(AlarmDay::Friday);
                break;
            case EditState::DaySaturday:
                toggleDay(AlarmDay::Saturday);
                break;
            case EditState::DaySunday:
                toggleDay(AlarmDay::Sunday);
                break;
            case EditState::Confirm:
                if(isNew){
                    registry.Remove(alarmIndex);
                }
                Manager.MoveTo(*menu);
                break;
        }
    }
}

void AlarmEdit::Reset() {
    state = EditState::Hours;
}

bool AlarmEdit::isDay(AlarmDay day) {
    return (alarm.days & day) == day;
}

void AlarmEdit::toggleDay(AlarmDay day) {
    alarm.days = alarm.days ^ day;
}

void AlarmEdit::Load(uint8_t newAlarmIndex, bool isNewAlarm) {
    alarmIndex = newAlarmIndex;
    alarm = registry[alarmIndex];
    isNew = isNewAlarm;
}

EditState operator++(EditState &state, int) {
    return static_cast<EditState>(static_cast<uint8_t>(state) + 1);
}

EditState operator--(EditState &state, int) {
    return static_cast<EditState>(static_cast<uint8_t>(state) - 1);
}
