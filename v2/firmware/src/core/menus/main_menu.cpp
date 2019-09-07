#include "./main_menu.hpp"

void MainMenu::Render(Display& display){
    display.SetCursor(20,2);
    display.Write("Menu", 2);

    display.Line(18);

    display.SetCursor(2,20);
    display.Write("1: Time", 1);

    display.SetCursor(2,30);
    display.Write("2: Alarms", 1);

    display.SetCursor(2,40);
    display.Write("3: Back", 1);
}

void MainMenu::OnButton(uint8_t button){
    switch (button)
    {
    case 0:
        Manager.MoveTo(*setTime);
        break;
    case 1:
        Manager.MoveTo(*alarmList);
        break;
    case 2:
        Manager.MoveTo(*home);
        break;
    }
}