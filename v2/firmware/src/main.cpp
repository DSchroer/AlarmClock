#define F_CPU 800000UL

#include <display.hpp>

#include "utils/menu_manager.hpp"
#include "menus/home.hpp"

int main() {
    Clock clock;
    Display display;
    MenuManager manager;

    Home main{manager, clock};

    manager.MoveTo(main);

    for (;;) {
        display.Clear();

        clock.Tick();
        manager.Update();

        manager.Render(display);

        display.Flush();
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