#define F_CPU 800000UL

#include "../drivers/include/display.hpp"
#include <drivers/buttons.hpp>
#include <cstdio>

#include "utils/menu_manager.hpp"

#include "menus/home.hpp"
#include "menus/alarm_menu.hpp"
#include "menus/main_menu.hpp"
#include "menus/set_time.hpp"

#include "alarms/alarm_manager.hpp"

#include "utils/vector.hpp"

int main() {
    Clock clock;
    Display display;
    Button button;

    MenuManager manager {button};

    //Menus
    MainMenu rootMenu {manager};

    Home main {manager, clock, rootMenu};
    SetTime setTime {manager, clock, rootMenu};

    AlarmRegistry registry{};
    registry.Add(Alarm{17, 19, AlarmDay ::All});

    AlarmManager alarmManager{registry};

    AlarmMenu alarmMenu{manager, alarmManager};

    rootMenu.home = &main;
    rootMenu.setTime = &setTime;

    manager.MoveTo(main);

    for (;;) {
        display.Clear();

        clock.Tick();
        button.Tick();

        if(alarmManager.Test(clock.time)){
            manager.MoveTo(alarmMenu);
        }

        manager.Update();

        manager.Render(display);

        display.Flush();
    }
}