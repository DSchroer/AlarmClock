#include "buzzer.hpp"
#include <avr/io.h>

#define BUZZER (1 << 4)

void init_buzzer()
{
    DDRD |= BUZZER;
}

void set_buzzer(bool turnedOn)
{
    if (turnedOn)
        PORTD |= BUZZER;
    else
        PORTD &= ~BUZZER;
}