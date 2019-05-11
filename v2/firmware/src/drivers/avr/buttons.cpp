#include "drivers/buttons.hpp"
#include "io.hpp"

#include <stdbool.h>

uint8_t last_buttons;
uint8_t buttons;

Button::Button(uint8_t index): index{index} {
    buttons = 0;
    last_buttons = 0;
}

void Button::Tick() {
    last_buttons = buttons;
    buttons = PIND;
}

bool Button::Pressed() {
    return (buttons & (1 << index)) && !(last_buttons & (1 << index)) ? true : false;
}