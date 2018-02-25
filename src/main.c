#include "main.h"

#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "button.h"
#include "lib/lcd.h"
#include "rtc.h"

rtc_t time;
uint8_t last_second;

void main_menu();
void alarm_menu();
void set_time();
void display_time();

char *main_menu_options[] = {
    "Set Time",
    "Alarms",
    "Cancel"};

char *alarm_menu_options[] = {
    "New Alarm",
    "Edit Alarms",
    "Delete Alarm",
    "Cancel"};

uint8_t
get_number(const char *display, uint8_t value, uint8_t min, uint8_t max);
uint8_t get_select(const char *display, char **options, uint8_t value, uint8_t max);

int main() {

    DDRD |= BUZZER;
    PORTD = 0x00;

    lcd_init(LCD_DISP_ON);

    lcd_clrscr();
    while (true) {
        btn_update();

        button_state state = btn_state_raw();
        if (state == button_down_long) {
            open_menu();
            lcd_clrscr();
            btn_reset();
        }

        rtc_get_time(&time);
        display_time();
    }
}

void display_time() {
    if (time.seconds == last_second) {
        return;
    }

    last_second = time.seconds;
    char display[34];

    char *day = days[time.day - 1];
    char *month = months[time.month - 1];

    sprintf(display, "%d:%02d:%02d\n%s %s %d 20%d", time.hours, time.minutes, time.seconds, day, month, time.date, time.year);

    lcd_clrscr();
    lcd_puts(display);
}

void main_menu() {
    uint8_t option = get_select("Menu:\n", main_menu_options, 0, 2);
    if (option == 0) {
        set_time();
    } else if (option == 1) {
        alarm_menu();
    }
}

void alarm_menu() {
    uint8_t option = get_select("Menu:\n", alarm_menu_options, 0, 3);
}

void set_time() {
    time.year = get_number("Year: 20", time.year, 0, 99);
    time.month = get_number("Month: ", time.month, 1, 12);
    time.date = get_number("Day: ", time.date, 1, 31);
    time.day = get_select("Weekday: ", days, time.day - 1, 6) + 1;

    time.hours = get_number("Hour: ", time.hours, 0, 23);
    time.minutes = get_number("Minute: ", time.minutes, 0, 59);
    time.seconds = get_number("Seconds: ", time.seconds, 0, 59);

    rtc_set_time(&time);
}

uint8_t get_number(const char *display, uint8_t value, uint8_t min, uint8_t max) {
    char str[4];

    lcd_clrscr();
    lcd_puts(display);
    sprintf(str, "%02d", value);
    lcd_puts(str);

    btn_reset();
    while (true) {
        btn_update();

        button_state state = btn_state();
        if (state == button_down_short) {
            if (++value > max) {
                value = min;
            }

            lcd_clrscr();
            lcd_puts(display);
            sprintf(str, "%02d", value);
            lcd_puts(str);
        }

        state = btn_state_raw();
        if (state == button_down_long) {
            break;
        }

        sleep();
    }

    return value;
}

uint8_t get_select(const char *display, char **options, uint8_t value, uint8_t max) {
    lcd_clrscr();
    lcd_puts(display);
    lcd_puts(options[value]);

    btn_reset();
    while (true) {
        btn_update();

        button_state state = btn_state();
        if (state == button_down_short) {
            if (++value > max) {
                value = 0;
            }

            lcd_clrscr();
            lcd_puts(display);
            lcd_puts(options[value]);
        }

        state = btn_state_raw();
        if (state == button_down_long) {
            break;
        }

        sleep();
    }

    return value;
}