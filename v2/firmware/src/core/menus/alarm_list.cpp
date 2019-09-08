#include <stdio.h>
#include "./alarm_list.hpp"

void AlarmList::Render(Display &display) {
    display.SetCursor(23, 2);
    display.Write("Alarms", 1);
    display.Line(11);

    RenderLine(15, position, display);

    switch (menuState) {
        case MenuState::List:
            display.Line(7, 23, 66);
            break;
        case MenuState::Alarm:
            display.Line(25, 23, 45);
            break;
    }

    RenderLine(25, position + 1, display);
    RenderLine(35, position + 2, display);
}

void AlarmList::RenderLine(uint8_t y, uint8_t renderPos, Display &display) {
    display.SetCursor(8, y);

    if (renderPos == 0) {
        display.Write("Add Alarm", 1);
        return;
    }

    if (renderPos > registry.Count) {
        return;
    }

    auto alarm = registry[renderPos - 1];

    char buffer[6];
    snprintf(buffer, sizeof(buffer), "#%d ", renderPos);
    display.Write(buffer, 1);

    if (menuState == MenuState::List) {
        if (alarm.enabled) {
            display.Write("Ready");
        } else {
            display.Write("Paused");
        }
    }

    if (renderPos == position && menuState == MenuState::Alarm) {
        switch (alarmViewState) {
            case AlarmViewState::Pause:
                if (alarm.enabled) {
                    display.Write("Pause");
                } else {
                    display.Write("Unpause");
                }
                break;
            case AlarmViewState::Edit:
                display.Write("Edit");
                break;
            case AlarmViewState::Delete:
                display.Write("Delete");
                break;
        }
    }
}

void AlarmList::OnButton(uint8_t button) {
    if (menuState == MenuState::List) {
        if (button == 1) {
            if (position > 0) {
                position--;
            }
        } else if (button == 2) {
            if (position < registry.Count) {
                position++;
            }
        } else if (button == 3) {
            if (position == 0) {
                Alarm newAlarm{};
                registry.Add(newAlarm);
                editMenu.alarmIndex = registry.Count - 1;
                Manager.MoveTo(editMenu);
            } else {
                menuState = MenuState::Alarm;
            }
        } else if (button == 0) {
            registry.Save();
            Manager.MoveTo(mainMenu);
        }
    } else if (menuState == MenuState::Alarm) {
        if (button == 2) {
            switch (alarmViewState) {
                case AlarmViewState::Pause:
                    alarmViewState = AlarmViewState::Edit;
                    break;
                case AlarmViewState::Edit:
                    alarmViewState = AlarmViewState::Delete;
                    break;
                case AlarmViewState::Delete:
                    alarmViewState = AlarmViewState::Pause;
                    break;
            }
        } else if (button == 1) {
            switch (alarmViewState) {
                case AlarmViewState::Pause:
                    alarmViewState = AlarmViewState::Delete;
                    break;
                case AlarmViewState::Edit:
                    alarmViewState = AlarmViewState::Pause;
                    break;
                case AlarmViewState::Delete:
                    alarmViewState = AlarmViewState::Edit;
                    break;
            }
        } else if (button == 3) {
            switch (alarmViewState) {
                case AlarmViewState::Pause: {
                    auto alarm = registry[position - 1];
                    alarm.enabled = !alarm.enabled;
                    registry[position - 1] = alarm;
                    break;
                }
                case AlarmViewState::Edit:
                    editMenu.alarmIndex = position - 1;
                    Manager.MoveTo(editMenu);
                    break;
                case AlarmViewState::Delete:
                    registry.Remove(--position);
                    menuState = MenuState::List;
                    break;
            }
        } else if (button == 0) {
            menuState = MenuState::List;
        }
    }
}

void AlarmList::Reset() {
    menuState = MenuState::List;
    position = 0;
    alarmViewState = AlarmViewState::Pause;
}
