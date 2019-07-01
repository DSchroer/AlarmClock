#include <drivers/rtc.hpp>

extern "C" {
#include "../lib/i2c_master.h"
}

#define RTC_READ_ADDR 0xD1u
#define RTC_WRITE_ADDR 0xD0u

#define bin_bcd(num) (((num) / 10) * 16) + ((num) % 10)
#define bdc_bin(num) (((num) / 16) * 10) + ((num) % 16)

// const char *rtc_ordinal(uint8_t date) {
//     switch (date % 100) {
//         case 11:
//         case 12:
//         case 13:
//             return "th";
//         default:
//             switch (date % 10) {
//                 case 1:
//                     return "st";
//                 case 2:
//                     return "nd";
//                 case 3:
//                     return "rd";
//                 default:
//                     return "th";
//             }
//     }
// }

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
}

void rtc_set_time(Time &time) {
    for (unsigned int i = 0; i < sizeof(Time); i++) {
        ((uint8_t *)&time)[i] = bin_bcd(((uint8_t *)&time)[i]);
    }

    i2c_writeReg(RTC_WRITE_ADDR, 0, (uint8_t *)&time, sizeof(Time));
}

Clock::Clock(){
    Tick();
}

void Clock::Tick(){
    rtc_get_time(time);
}