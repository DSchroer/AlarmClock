#include <drivers/buttons.hpp>
#include "drivers/light.hpp"
#include "io.hpp"

#define LIGHT (1 << 5)

Light::Light() {
    DDRB |= LIGHT;
}

void Light::SetLight(bool turnedOn) {
    if (turnedOn)
        PORTB |= LIGHT;
    else
        PORTB &= ~LIGHT;
}

void Light::Tick(Time &time, Button& button) {
    static uint8_t remaining = 0;
     static uint8_t seconds = 0;

     if (button.Any())
     {
         remaining = 10;
     }

     if (seconds != time.seconds)
     {
         seconds = time.seconds;

         if (remaining > 0)
             remaining--;
     }

    SetLight(remaining > 0);
}