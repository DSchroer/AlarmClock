#define F_CPU 1000000UL

#ifdef EDITOR
#include <avr/iom32.h>
#endif
#include <util/delay.h>

#include "alarm.h"

#define LIGHT (1 << 1)
#define BUZZER (1 << 4)
#define BUTTON (1 << 7)

#define delay(ms) _delay_ms(ms)
#define sleep() delay(10);

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
void update_light(uint8_t *light);
void enable_light(uint8_t *light);
