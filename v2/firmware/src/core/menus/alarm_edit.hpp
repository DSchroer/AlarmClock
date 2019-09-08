#pragma once

#include <utils/menu_manager.hpp>
#include <alarms/alarm.hpp>
#include <alarms/alarm_manager.hpp>

class AlarmEdit: public Menu {
private:
    Alarm alarm;
    AlarmRegistry& registry;

public:
    explicit AlarmEdit(MenuManager& manager, AlarmRegistry& registry): Menu{manager}, registry{registry} {};

    uint8_t alarmIndex;

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
    void Reset() override;
};
