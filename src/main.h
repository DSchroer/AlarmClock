#define F_CPU 1000000UL

#ifdef EDITOR
#include <avr/iom32.h>
#endif
#include <util/delay.h>

#define BUZZER (1 << 4)
#define BUTTON (1 << 7)

#define delay(ms) _delay_ms(ms)
#define sleep() delay(10);
