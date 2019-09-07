#pragma once

#include <alarms/alarm_registry.hpp>
#include "../utils/menu_manager.hpp"
#include "alarm_edit.hpp"

enum class MenuState{
    List,
    Alarm
};

enum class AlarmViewState{
    Pause,
    Edit,
    Delete
};

class AlarmList: public Menu {
private:
    uint8_t position = 0;
    MenuState menuState = MenuState::List;
    AlarmViewState alarmViewState = AlarmViewState::Pause;

    AlarmRegistry& registry;
    Menu& mainMenu;
    AlarmEdit& editMenu;

public:
    explicit AlarmList(MenuManager& manager, AlarmRegistry& registry1, Menu& main, AlarmEdit& edit): Menu{manager}, registry{registry1}, mainMenu{main}, editMenu{edit} {};

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
    void Reset() override;

    void RenderLine(uint8_t y, uint8_t renderPos, Display& display);
};