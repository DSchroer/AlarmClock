#pragma once
#include <stdbool.h>

void init_buzzer();
void set_buzzer(bool turnedOn);

class Buzzer
{
public:
    Buzzer();

    void SetBuzzer(bool turnedOn);
};
