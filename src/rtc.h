#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day;
    uint8_t date;
    uint8_t month;
    uint8_t year;
} rtc_t;

char *months[12];
char *days[7];

void rtc_get_time(rtc_t *time);
void rtc_set_time(rtc_t *time);
