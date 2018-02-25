#pragma once

typedef enum {
    button_up,
    button_down_long,
    button_down_short
} button_state;

void btn_reset();
void btn_update();
button_state btn_state();
button_state btn_state_raw();
