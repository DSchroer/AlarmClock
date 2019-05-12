#define F_CPU 800000UL

#include <drivers/display.hpp>

using namespace Alarm;

int main() {
    Display display{};

    display.Write("test", 1);
    display.Flush();
    for (;;) {
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