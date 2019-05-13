#pragma once

#include "stdint.h"
#include "drivers/screen.hpp"

class Display : public Screen {
  public:
    uint8_t X;
    uint8_t Y;

    Display(): X{0} ,Y{0} {}
    ~Display() {}

    void SetCursor(uint8_t x, uint8_t y);
    void Write(const char *message, uint8_t scale = 1);
    void Write(char character, uint8_t scale = 1);
    void Line(uint8_t y);
};