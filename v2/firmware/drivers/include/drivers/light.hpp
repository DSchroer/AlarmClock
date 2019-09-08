#pragma once

#include <time.hpp>
#include "buttons.hpp"

class Light
{
public:
    Light();

    void Tick(Time& time, Button& button);
    void SetLight(bool turnedOn);
};