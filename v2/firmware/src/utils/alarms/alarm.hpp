#pragma once

#include "./alarm_day.hpp"
#include <stdint.h>

struct Alarm
{
    uint8_t hour;
    uint8_t time;
    AlarmDay days;
    bool enabled;
};
