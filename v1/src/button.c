#include "button.h"
#include "main.h"

#include <avr/io.h>
#include <stdbool.h>

#define LONG_PRESS 100
#define SHORT_PRESS 4

uint8_t counter;
button_state state;

void btn_reset() {
    while (true) {
        btn_update(0);
        if (!(PIND & BUTTON)) {
            break;
        }
        sleep();
    }
}

void btn_update(uint8_t multiplier) {
    state = button_up;
    if (PIND & BUTTON) {
        counter += (1 << multiplier);
    } else if (counter) {
        if (counter >= LONG_PRESS) {
            state = button_down_long;
        } else if (counter >= SHORT_PRESS) {
            state = button_down_short;
        }
        counter = 0;
    }
}

button_state btn_state() {
    return state;
}

button_state btn_state_raw() {
    if (counter >= LONG_PRESS) {
        return button_down_long;
    } else if (counter >= SHORT_PRESS) {
        return button_down_short;
    } else {
        return button_up;
    }
}