#define F_CPU 800000UL

#include <display.hpp>
#include <drivers/buttons.hpp>

#include "utils/menu_manager.hpp"

#include "menus/home.hpp"
#include "menus/main_menu.hpp"
#include "menus/set_time.hpp"

#include "utils/alarms/alarm_registry.hpp"

int main() {
    Clock clock;
    Display display;
    Button button;

    MenuManager manager {button};

    //Menus
    MainMenu rootMenu {manager};

    Home main {manager, clock, rootMenu};
    SetTime setTime {manager, clock, rootMenu};

    rootMenu.home = &main;
    rootMenu.setTime = &setTime;

    manager.MoveTo(main);

    for (;;) {
        display.Clear();

        clock.Tick();
        button.Tick();

        manager.Update();

        manager.Render(display);

        display.Flush();
    }
}