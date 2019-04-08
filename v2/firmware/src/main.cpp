#include "main.hpp"

#include <avr/io.h>
#include <util/delay.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils/buzzer.hpp"
#include "utils/display.hpp"
#include "utils/buttons.hpp"

#define BUTTON (1 << 3)

int main()
{
    Time time;

    initialize();

    for (;;)
    {
        rtc_get_time(time);
        update(time);
    }
}

void initialize()
{
    init_buzzer();
    init_display();
    btn_init();
}

void update(Time &time)
{
    btn_update();
    draw_display(time);
}