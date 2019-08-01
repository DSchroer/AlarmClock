#define F_CPU 800000UL

#include "../drivers/include/display.hpp"
#include <drivers/buttons.hpp>
#include <cstdio>

#include "utils/menu_manager.hpp"

#include "menus/home.hpp"
#include "menus/main_menu.hpp"
#include "menus/set_time.hpp"

#include "alarms/alarm_manager.hpp"

#include "utils/vector.hpp"

int main() {

    Vector<uint8_t > data;
    data.Add(5);
    data.Add(10);
    data.Add(1);

    for(int i = 0; i < data.Count; i++){
        printf("%d\n", data[i]);
    }

//    Clock clock;
//    Display display;
//    Button button;
//
//    MenuManager manager {button};
//
//    //Menus
//    MainMenu rootMenu {manager};
//
//    Home main {manager, clock, rootMenu};
//    SetTime setTime {manager, clock, rootMenu};
//
//    rootMenu.home = &main;
//    rootMenu.setTime = &setTime;
//
//    manager.MoveTo(main);
//
//    for (;;) {
//        display.Clear();
//
//        clock.Tick();
//        button.Tick();
//
//        manager.Update();
//
//        manager.Render(display);
//
//        display.Flush();
//    }
}