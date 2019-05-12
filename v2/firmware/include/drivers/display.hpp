#pragma once
#include "stdint.h"

namespace Alarm {

class Display {
  public:
    Display();
    ~Display();

    uint8_t x;
    int y;

    void SetCursor(int x, int y);
    void Write(const char *message, int scale = 1);
    void Write(char character, int scale = 1);
    void Pixel(int x, int y);
    void Flush();
    void Clear();
};

} // namespace Alarm
