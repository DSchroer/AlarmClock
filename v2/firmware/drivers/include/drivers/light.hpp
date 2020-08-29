#pragma once

#include <time.hpp>
#include "buttons.hpp"

class Light
{
private:
    uint8_t seconds = 0;
    uint8_t remaining = 0;
    uint8_t active = 0;

    const uint8_t MAX_SECONDS = 10;

public:
    Light();

    void SetLight(bool turnedOn);

    uint8_t ActiveFor() {
        return active;
    }

    void Tick(Time& time, Button& button){
        if (button.Any()) {
            remaining = MAX_SECONDS;
        }

        if (seconds != time.seconds) {
            seconds = time.seconds;

            active++;
            if (remaining > 0){
                remaining--;
            }
        }

        if(remaining == 0){
            SetLight(false);
            active = 0;
        }else{
            SetLight(true);
        }
    }
};