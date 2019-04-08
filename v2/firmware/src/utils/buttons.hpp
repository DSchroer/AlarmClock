#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void btn_init();
void btn_update();
bool btn_any_pressed();
bool btn_pressed(uint8_t number);
