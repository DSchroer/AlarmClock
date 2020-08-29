#pragma once
#include <drivers/rtc.hpp>
#include "display.hpp"

void DrawTime(Display& display, const Time& time);
void DrawDateTime(Display& display, const Time& time);
void DrawConfirm(Display& display);