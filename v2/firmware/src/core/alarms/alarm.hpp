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

    Alarm(): minute{0}, hour{0}, days{AlarmDay::None}, enabled{true} {};
    Alarm(uint8_t minute, uint8_t hour, AlarmDay days = AlarmDay::None): minute{minute}, hour{hour}, days{days}, enabled{true} {};

    bool operator== (const Time& time);
    Alarm operator+ (const uint8_t minutes);
};
