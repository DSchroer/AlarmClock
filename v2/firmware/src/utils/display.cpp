#include <stdio.h>

#include "display.hpp"

#include "../headers/light.hpp"
#include "menus.hpp"

enum class MenuState
{
    DISPLAY_TIME,
    MAIN_MENU,
    ALARM_MENU,
    TIME_MENU,
    EDIT_TIME,
    EDIT_ALARM
};

MenuState menu_state{MenuState::DISPLAY_TIME};

void init_display()
{
    init_light();
    // nokia_lcd_init();
}

void button_transition(uint8_t button, MenuState state)
{
    // if (btn_pressed(button))
    // {
    //     menu_state = state;
    // }
}

void draw_display(Time &time)
{
    update_light(time);

    switch (menu_state)
    {
    case MenuState::MAIN_MENU:
        button_transition(0, MenuState::DISPLAY_TIME);
        break;
    default:
        button_transition(3, MenuState::MAIN_MENU);
        draw_main_menu(time);
        break;
    }
}
