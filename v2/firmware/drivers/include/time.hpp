#pragma once

#include <stdint.h>

struct Time
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day;
    uint8_t date;
    uint8_t month;
    uint8_t year;
    uint8_t control;
};

bool operator >(const Time& lhs, const Time& rhs);
bool operator <(const Time& lhs, const Time& rhs);
bool operator ==(const Time& lhs, const Time& rhs);