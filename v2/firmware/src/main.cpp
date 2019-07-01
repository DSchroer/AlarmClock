#define F_CPU 800000UL

#include <display.hpp>
#include <drivers/buttons.hpp>

#include "utils/menu_manager.hpp"

#include "menus/home.hpp"
#include "menus/main_menu.hpp"

int main() {
    Clock clock;
    Display display;
    Button button;

    MenuManager manager {button};

    //Menus
    MainMenu rootMenu {manager};
    Home main {manager, clock, rootMenu};

    manager.MoveTo(rootMenu);

    for (;;) {
        display.Clear();

        clock.Tick();
        button.Tick();

        manager.Update();

        manager.Render(display);

        display.Flush();
    }
}