#pragma once

#include <alarms/alarm_manager.hpp>
#include "../utils/menu_manager.hpp"

class AlarmMenu: public Menu {
private:
    AlarmManager& alarmManager;
    Menu& menu;
public:
    explicit AlarmMenu(MenuManager& manager, AlarmManager& alarms, Menu& menu):
        Menu{manager}, alarmManager{alarms}, menu{menu} {};

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
};
