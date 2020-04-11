#define F_CPU 800000UL

#include <drivers/buttons.hpp>
#include <menus/alarm_edit.hpp>
#include <drivers/light.hpp>
#include <drivers/storage.hpp>

#include "utils/menu_manager.hpp"

#include "menus/home.hpp"
#include "menus/alarm_list.hpp"
#include "menus/alarm_menu.hpp"
#include "menus/main_menu.hpp"
#include "menus/set_time.hpp"
#include "menus/list_menu.hpp"

#include "alarms/alarm_manager.hpp"

#include "./allocation.cpp"

int main() {
    Clock clock;
    Display display;
    Button button;
    Light light;
    Buzzer buzzer;
    Storage storage;

    MenuManager manager {button};
    ListMenu rootMenu {manager, "Menu", Vector<Option>{}};

    Home main {manager, clock, rootMenu};
    rootMenu.SetParent(main);

    SetTime setTime {manager, clock, rootMenu};
    rootMenu.AddOption(Option{Vector<State*>{new NavState{"Clock", manager, setTime}}});

    AlarmRegistry registry{storage};
    registry.Load();

    AlarmManager alarmManager{registry};

    AlarmMenu alarmMenu{manager, alarmManager, main, light, buzzer, clock};

    AlarmEdit alarmEdit{manager, registry};
    AlarmList alarmList{manager, registry, rootMenu, alarmEdit, alarmManager};
    rootMenu.AddOption(Option{Vector<State*>{new NavState{"Alarms", manager, alarmList}}});

    alarmEdit.menu = &alarmList;
    manager.MoveTo(main);

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
