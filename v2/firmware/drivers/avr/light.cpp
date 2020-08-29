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