#pragma once

#include <alarms/alarm_manager.hpp>
#include "../utils/menu_manager.hpp"

class AlarmMenu: public Menu {
private:
    AlarmManager& alarmManager;
public:
    explicit AlarmMenu(MenuManager& manager, AlarmManager& alarms):
        Menu{manager}, alarmManager{alarms} {};

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
};
