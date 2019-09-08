#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

class Button
{
public:
    Button();

    void Tick();
    bool Pressed(uint8_t index);
    bool Any();
};
