#pragma once;
#include "rtc.h"
#include <stdint.h>

typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t day_flags;
} alarm_t;

void load_alarms();
bool alrm_update(rtc_t *time);

uint8_t alarm_count();
void add_alarm(alarm_t alarm);
alarm_t get_alarm(uint8_t index);
void set_alarm(uint8_t index, alarm_t alarm);
void delete_alarm(uint8_t index);
