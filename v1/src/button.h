#pragma once

#include <stdint.h>

typedef enum {
    button_up,
    button_down_long,
    button_down_short
} button_state;

void btn_reset();
void btn_update(uint8_t multiplier);
button_state btn_state();
button_state btn_state_raw();
