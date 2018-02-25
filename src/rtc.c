#include "rtc.h"
#include "lib/i2c_master.h"

#define RTC_READ_ADDR 0xD1u
#define RTC_WRITE_ADDR 0xD0u

#define bin_bcd(num) (((num) / 10) * 16) + ((num) % 10)
#define bdc_bin(num) (((num) / 16) * 10) + ((num) % 16)

char *months[] = {
    "Jan",
    "Feb",
    "Mar"
    "Apr"
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"};

char *days[] = {
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat"};

void rtc_reset_position() {
    i2c_init();
    i2c_start(RTC_WRITE_ADDR);
    i2c_write(0);
    i2c_stop();
}

void rtc_get_time(rtc_t *time) {
    rtc_reset_position();
    i2c_receive(RTC_READ_ADDR, (uint8_t *)time, sizeof(rtc_t));

    for (int i = 0; i < sizeof(rtc_t); i++) {
        ((uint8_t *)time)[i] = bdc_bin(((uint8_t *)time)[i]);
    }
}

void rtc_set_time(rtc_t *time) {
    for (int i = 0; i < sizeof(rtc_t); i++) {
        ((uint8_t *)time)[i] = bin_bcd(((uint8_t *)time)[i]);
    }

    i2c_writeReg(RTC_WRITE_ADDR, 0, (uint8_t *)time, sizeof(rtc_t));
}
