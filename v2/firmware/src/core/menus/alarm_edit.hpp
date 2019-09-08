#pragma once

#include <utils/menu_manager.hpp>
#include <alarms/alarm.hpp>
#include <alarms/alarm_manager.hpp>

enum class EditState {
    Hours,
    Minutes,
    DayMonday,
    DayTuesday,
    DayWednesday,
    DayThursday,
    DayFriday,
    DaySaturday,
    DaySunday,
    Confirm
};

EditState operator++(EditState&, int);
EditState operator--(EditState&, int);

class AlarmEdit: public Menu {
private:

    Alarm alarm;
    AlarmRegistry& registry;

    EditState state;

    bool isDay(AlarmDay day);
    void toggleDay(AlarmDay day);
public:
    explicit AlarmEdit(MenuManager& manager, AlarmRegistry& registry): Menu{manager}, registry{registry} {};

    uint8_t alarmIndex;
    Menu* menu;

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
    void Reset() override;
};
