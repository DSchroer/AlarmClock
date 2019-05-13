#define F_CPU 800000UL

#include <display.hpp>

#include "utils/menu_manager.hpp"
#include "menus/main_menu.hpp"

int main() {
    Display display;
    MenuManager manager;

    MainMenu main{manager};

    manager.MoveTo(main);

    for (;;) {
        display.Clear();

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