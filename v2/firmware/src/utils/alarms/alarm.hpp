#pragma once

#include "./alarm_day.hpp"
#include <stdint.h>
#include <time.hpp>

struct Alarm
{
    uint8_t hour;
    uint8_t minute;
    AlarmDay days;
    bool enabled;

    bool operator== (const Time& time){
        return enabled && time.hours == hour &&  time.minutes == minute;
    }
};
