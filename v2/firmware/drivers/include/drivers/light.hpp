#pragma once

#include <time.hpp>

class Light
{
public:
    Light();

    void Tick(Time& time, Button& button);
    static void SetLight(bool turnedOn);
};