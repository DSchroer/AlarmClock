#pragma once

#include <stdbool.h>
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
};

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
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"};

const char *rtc_ordinal(uint8_t date);

void rtc_get_time(Time &time);
void rtc_set_time(Time &time);
