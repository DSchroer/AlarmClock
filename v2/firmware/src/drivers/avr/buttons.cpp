#include "buttons.hpp"
#include "io.hpp"

#include <stdbool.h>

uint8_t last_buttons;
uint8_t buttons;

void btn_init()
{
    buttons = 0;
}

void btn_update()
{
    last_buttons = buttons;
    buttons = PIND;
}

bool btn_any_pressed()
{
    return (buttons & 0x0F) && !(last_buttons & 0x0F) ? true : false;
}

bool btn_pressed(uint8_t number)
{
    return (buttons & (1 << number)) && !(last_buttons & (1 << number)) ? true : false;
}