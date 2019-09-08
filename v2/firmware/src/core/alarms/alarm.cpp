#include "alarm.hpp"

Alarm Alarm::operator+ (const uint8_t minutes){
    Alarm newAlarm{};
    newAlarm.minute = minute;
    newAlarm.hour = hour;
    newAlarm.enabled = true;
    newAlarm.days = AlarmDay::All;

    newAlarm.minute += minutes;
    if(newAlarm.minute >= 60){
        newAlarm.minute -= 60;
        newAlarm.hour += 1;
        if(newAlarm.hour >= 24){
            newAlarm.hour -= 24;
        }
    }

    return newAlarm;
}

bool Alarm::operator==(const Time &time) {
    auto day = time.day;
    if(day == 0){
        day = 1;
    }

    return enabled &&
           time.seconds == 0 &&
           time.hours == hour &&
           time.minutes == minute &&
           (days & static_cast<AlarmDay>(((uint8_t)1) << (day - ((uint8_t)1)))) != AlarmDay::None;
}
