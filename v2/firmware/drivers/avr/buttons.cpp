#include "io.hpp"
#include <drivers/buttons.hpp>

#include <stdbool.h>

uint8_t last_buttons;
uint8_t buttons;

Button::Button() {
    buttons = 0;
    last_buttons = 0;
}

void Button::Tick() {
    last_buttons = buttons;
    buttons = PIND;
}

bool Button::Pressed(uint8_t index) {
    return (buttons & (1 << index)) && !(last_buttons & (1 << index)) ? true : false;
}