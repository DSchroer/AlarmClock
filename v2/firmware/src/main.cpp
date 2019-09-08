#define F_CPU 800000UL

#include "../drivers/include/display.hpp"
#include <drivers/buttons.hpp>
#include <stdio.h>
#include <menus/alarm_edit.hpp>
#include <drivers/light.hpp>

#include "utils/menu_manager.hpp"

#include "menus/home.hpp"
#include "menus/alarm_list.hpp"
#include "menus/alarm_menu.hpp"
#include "menus/main_menu.hpp"
#include "menus/set_time.hpp"

#include "alarms/alarm_manager.hpp"

#include "utils/vector.hpp"

int main() {
    Clock clock;
    Display display;
    Button button;
    Light light;

    MenuManager manager {button};

    //Menus
    MainMenu rootMenu {manager};

    Home main {manager, clock, rootMenu};
    SetTime setTime {manager, clock, rootMenu};

    AlarmRegistry registry{};
    registry.Add(Alarm{17, 19, AlarmDay ::All});

    AlarmManager alarmManager{registry};

    AlarmMenu alarmMenu{manager, alarmManager};

    AlarmEdit alarmEdit{manager, registry};
    AlarmList alarmList{manager, registry, rootMenu, alarmEdit};

    rootMenu.home = &main;
    rootMenu.setTime = &setTime;
    rootMenu.alarmList = &alarmList;

    manager.MoveTo(main);

//    alarmEdit.alarmIndex = 0;
//    manager.MoveTo(alarmEdit);

    for (;;) {
        display.Clear();

        clock.Tick();
        button.Tick();
        light.Tick(clock.time, button);

        if(alarmManager.Test(clock.time)){
            manager.MoveTo(alarmMenu);
        }

        manager.Update();

        manager.Render(display);

        display.Flush();
    }
}