#include <drivers/rtc.hpp>

extern "C" {
#include "lib/i2c_master.h"
}

#define RTC_READ_ADDR 0xD1u
#define RTC_WRITE_ADDR 0xD0u

#define bin_bcd(num) (((num) / 10) * 16) + ((num) % 10)
#define bdc_bin(num) (((num) / 16) * 10) + ((num) % 16)

void rtc_reset_position() {
    i2c_init();
    i2c_start(RTC_WRITE_ADDR);
    i2c_write(0);
    i2c_stop();
}

void rtc_get_time(Time &time) {
    rtc_reset_position();
    i2c_receive(RTC_READ_ADDR, (uint8_t *)&time, sizeof(Time));

    for (unsigned int i = 0; i < sizeof(Time); i++) {
        ((uint8_t *)&time)[i] = bdc_bin(((uint8_t *)&time)[i]);
    }

    time.day &= 0b00000111;
    time.date &= 0b00111111;
    time.month &= 0b00011111;
    time.year &= 0b11111111;
}

void rtc_set_time(Time &time) {
    for (unsigned int i = 0; i < sizeof(Time); i++) {
        ((uint8_t *)&time)[i] = bin_bcd(((uint8_t *)&time)[i]);
    }

    // Turn off the CH bit
    time.seconds = ~(0 << 7) & time.seconds;

    i2c_writeReg(RTC_WRITE_ADDR, 0, (uint8_t *)&time, sizeof(Time));
}

Clock::Clock(){
    Tick();
}

void Clock::Tick(){
    rtc_get_time(time);
}

void Clock::SetTime(Time& time){
    rtc_set_time(time);
}