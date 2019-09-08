#pragma once

#include <alarms/alarm_manager.hpp>
#include <drivers/light.hpp>
#include <drivers/buzzer.hpp>
#include "../utils/menu_manager.hpp"

class AlarmMenu: public Menu {
private:
    AlarmManager& alarmManager;
    Light& light;
    Buzzer& buzzer;
    Clock& clock;
    Menu& menu;
public:
    explicit AlarmMenu(MenuManager& manager, AlarmManager& alarms, Menu& menu, Light& light, Buzzer& buzzer, Clock& clock):
        Menu{manager}, alarmManager{alarms}, menu{menu}, light{light}, buzzer{buzzer}, clock{clock} {};

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
};
