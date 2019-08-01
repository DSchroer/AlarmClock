#pragma once

#include "stdint.h"

class Screen {
  public:
    Screen();
    ~Screen();

    void Pixel(uint8_t x, uint8_t y, uint8_t value = 1);
    void Flush();
    void Clear();
};