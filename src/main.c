#include "main.h"

#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "alarm.h"
#include "button.h"
#include "lib/lcd.h"
#include "rtc.h"

rtc_t time;
uint8_t last_second;

void main_menu();
void alarm_menu();
void set_time();
void display_time();
void edit_alarm(alarm_t *alarm);

uint8_t get_number(const char *display, uint8_t value, uint8_t min, uint8_t max);
uint8_t get_select(const char *display, char **options, uint8_t value, uint8_t max, uint8_t flags);
uint8_t get_alarm_days(uint8_t value);
void print_alarm_days(uint8_t value);
void trigger_alarm();

int main() {

    DDRD |= BUZZER;
    PORTD = 0x00;

    load_alarms();

    lcd_init(LCD_DISP_ON);
    lcd_clrscr();

    while (true) {
        btn_update(1);

        button_state state = btn_state_raw();
        if (state == button_down_long) {
            main_menu();
            lcd_clrscr();
            btn_reset();
        }

        rtc_get_time(&time);
        if (alrm_update(&time)) {
            trigger_alarm();
        }
        display_time();
    }
}

void trigger_alarm() {
    lcd_clrscr();
    lcd_puts("Good Morning\nZi Yue :)");

    PORTD |= BUZZER;
    uint8_t counter = 0;
    while (true) {
        btn_update(0);

        button_state state = btn_state_raw();
        if (state == button_down_long) {
            break;
        }

        if (++counter > 50) {
            PORTD ^= BUZZER;
            counter = 0;
        }
        sleep();
    }

    PORTD &= ~BUZZER;
}

void display_time() {
    if (time.seconds == last_second) {
        return;
    }

    last_second = time.seconds;

    char *day = days[time.day - 1];
    char *month = months[time.month - 1];

    char display[34];
    sprintf(display, "%d:%02d:%02d\n%s %s %d 20%d", time.hours, time.minutes, time.seconds, day, month, time.date, time.year);

    lcd_clrscr();
    lcd_puts(display);
}

char *main_menu_options[] = {
    "Time",
    "Alarms",
    "Cancel"};

void main_menu() {
    uint8_t option = get_select("Menu:\n", main_menu_options, 0, 2, 0);
    if (option == 0) {
        set_time();
    } else if (option == 1) {
        alarm_menu();
    }
}

char *alarm_menu_options[] = {
    "Add Alarm",
    "Edit Alarm",
    "Delete Alarm",
    "Clear Alarms",
    "Cancel"};

void alarm_menu() {
    uint8_t count = alarm_count();
    uint8_t flags = 0;
    if (count == 0) {
        flags |= (1 << 1) | (1 << 2) | (1 << 3);
    }

    uint8_t option = get_select("Menu:\n", alarm_menu_options, 0, 4, flags);
    if (option == 0) {

        alarm_t new;
        new.hour = 0;
        new.minute = 0;
        new.day_flags = 0;
        edit_alarm(&new);
        add_alarm(new);

    } else if (option == 1) {

        uint8_t index = get_number("Alarm #", 0, 0, count - 1);
        alarm_t current = get_alarm(index);
        edit_alarm(&current);
        set_alarm(index, current);

    } else if (option == 2) {

        uint8_t index = get_number("Alarm #", 0, 0, count - 1);
        delete_alarm(index);

    } else if (option == 3) {
        clear_alarms();
    }
}

void edit_alarm(alarm_t *alarm) {

    alarm->hour = get_number("Hour: ", alarm->hour, 0, 23);
    alarm->minute = get_number("Minute: ", alarm->minute, 0, 59);
    alarm->day_flags = get_alarm_days(alarm->day_flags);
}

void set_time() {
    time.year = get_number("Year: 20", time.year, 0, 99);
    time.month = get_number("Month: ", time.month, 1, 12);
    time.date = get_number("Day: ", time.date, 1, 31);
    time.day = get_select("Weekday: ", days, time.day - 1, 6, 0) + 1;

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
        btn_update(0);

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

uint8_t get_select(const char *display, char **options, uint8_t value, uint8_t max, uint8_t flags) {
    lcd_clrscr();
    lcd_puts(display);
    lcd_puts(options[value]);

    btn_reset();
    while (true) {
        btn_update(0);

        button_state state = btn_state();
        if (state == button_down_short) {
            do {
                value = (value + 1) % (max + 1);
            } while ((flags & (1 << value)) > 0);

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

uint8_t get_alarm_days(uint8_t value) {

    lcd_command(LCD_DISP_ON_CURSOR);
    lcd_clrscr();
    lcd_puts("Days: SMTWTFS\n      ");
    print_alarm_days(value);

    uint8_t ptr = 0;
    lcd_gotoxy(6 + ptr, 1);

    btn_reset();
    while (true) {
        btn_update(0);

        button_state state = btn_state();
        if (state == button_down_short) {
            value ^= (1 << ptr);
            lcd_clrscr();
            lcd_puts("Days: SMTWTFS\n      ");
            print_alarm_days(value);
            lcd_gotoxy(6 + ptr, 1);
        }

        state = btn_state_raw();
        if (state == button_down_long) {
            if (ptr < 6) {
                ptr++;
                lcd_gotoxy(6 + ptr, 1);
                btn_reset();
            } else {
                break;
            }
        }

        sleep();
    }
    lcd_command(LCD_DISP_ON);
    return value;
}

void print_alarm_days(uint8_t value) {
    for (uint8_t i = 0; i < 7; i++) {
        lcd_putc((value & (1 << i)) ? 0xFF : ' ');
    }
}