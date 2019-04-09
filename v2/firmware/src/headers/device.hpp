#pragma once

#include "buzzer.hpp"
#include "display.hpp"
#include "buttons.hpp"
#include "rtc.hpp"

class Device
{
private:
    Time time;

    Clock clock;
    Display display;
    Buzzer buzzer;
    ButtonGroup buttons;

public:
    Device();

    void Tick();
};

void Device::Tick(){
    clock.GetTime(time);

    buttons.Tick();
}
