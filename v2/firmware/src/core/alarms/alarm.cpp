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
    return enabled &&
           time.seconds == 0 &&
           time.hours == hour &&
           time.minutes == minute &&
           (days & static_cast<AlarmDay>(1 << time.day)) != AlarmDay::None;
}
