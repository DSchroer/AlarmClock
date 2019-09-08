#include "alarm_menu.hpp"

void AlarmMenu::Render(Display &display) {

    display.X = 5;
    display.Y = 5;
    display.Write("Good Morning!",1);

    display.X = 9;
    display.Y = 20;
    display.Write("1,2: Stop",1);

    display.X = 9;
    display.Y = 30;
    display.Write("3,4: Snooze",1);
}

void AlarmMenu::OnButton(uint8_t button) {
    if(button == 1 || button == 2){
        alarmManager.Stop();
        Manager.MoveTo(menu);
    } else if (button == 3 || button == 4){
        alarmManager.Snooze();
        Manager.MoveTo(menu);
    }
}


