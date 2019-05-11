#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

class Button
{
private:
    uint8_t index;
public:
    Button(uint8_t index);

    void Tick();
    bool Pressed();
};
