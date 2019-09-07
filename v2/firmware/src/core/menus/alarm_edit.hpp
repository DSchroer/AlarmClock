#pragma once

#include <utils/menu_manager.hpp>
#include <alarms/alarm.hpp>

class AlarmEdit: public Menu {

public:
    uint8_t alarmIndex;
    explicit AlarmEdit(MenuManager& manager): Menu{manager} {};

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
};
