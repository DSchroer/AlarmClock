
#include "alarm.h"
#include <avr/eeprom.h>
#include <stdlib.h>

#define SIZE_ADDR (void *)0x00
#define DATA_ADDR (void *)0x01

uint8_t alarms_l = 0;
alarm_t *alarms;

void load_alarms() {
    alarms_l = eeprom_read_byte(SIZE_ADDR);
    if (alarms_l == 255) {
        clear_alarms();
    }
    alarms = (alarm_t *)malloc(sizeof(alarm_t) * 255);
    eeprom_read_block(alarms, DATA_ADDR, sizeof(alarm_t) * alarms_l);
    eeprom_busy_wait();
}

void save_alarms() {
    eeprom_update_byte(SIZE_ADDR, alarms_l);
    for (uint16_t i = 0; i < sizeof(alarm_t) * alarms_l; i++) {
        uint8_t *position = (uint8_t *)alarms;
        eeprom_update_byte(DATA_ADDR + i, *(position + i));
    }
    eeprom_busy_wait();
}

void clear_alarms() {
    eeprom_update_byte(SIZE_ADDR, 0);
    load_alarms();
}

bool alrm_update(rtc_t *time) {
    uint8_t day = (1 << (time->day - 1));

    for (uint8_t i = 0; i < alarms_l; i++) {
        if (time->hours == alarms[i].hour &&
            time->minutes == alarms[i].minute &&
            (alarms[i].day_flags & day) > 0) {
            return true;
        }
    }

    return false;
}

uint8_t alarm_count() {
    return alarms_l;
}

bool add_alarm(alarm_t alarm) {
    if (alarms_l + 1 == 255) {
        return false;
    }

    alarms[alarms_l] = alarm;
    alarms_l += 1;

    save_alarms();
    return true;
}

alarm_t get_alarm(uint8_t index) {
    return alarms[index];
}

bool set_alarm(uint8_t index, alarm_t alarm) {
    if (index >= alarms_l) {
        return false;
    }

    alarms[index] = alarm;
    save_alarms();
    return true;
}

bool delete_alarm(uint8_t index) {
    if (index >= alarms_l || alarms_l == 0) {
        return false;
    }

    alarms[index] = alarms[alarms_l - 1];
    alarms_l -= 1;

    save_alarms();
    return true;
}