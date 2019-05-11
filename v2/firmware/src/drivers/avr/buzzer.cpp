#include "drivers/buzzer.hpp"
#include <avr/io.h>

#define BUZZER (1 << 4)

Buzzer::Buzzer(){
    DDRD |= BUZZER;
}

void Buzzer::SetBuzzer(bool turnedOn){
    if (turnedOn)
        PORTD |= BUZZER;
    else
        PORTD &= ~BUZZER;
}