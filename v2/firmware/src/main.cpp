#define F_CPU 800000UL

#include "headers/device.hpp"

int main()
{
    Device device;

    for (;;)
    {
        device.Tick();
    }
}

// void initialize()
// {
//     init_buzzer();
//     init_display();
//     btn_init();
// }

// void update(Time &time)
// {
//     btn_update();
//     draw_display(time);
// }