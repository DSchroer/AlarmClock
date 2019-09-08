#include "alarm_menu.hpp"

void AlarmMenu::Render(Display &display) {
    light.SetLight(true);
    buzzer.SetBuzzer(clock.time.seconds % 2 != 0);

    display.SetCursor(5,5);
    display.Write("Good Morning!");

    display.SetCursor(9, 20);
    display.Write("1,2: Stop");

    display.SetCursor(9, 30);
    display.Write("3,4: Snooze");
}

void AlarmMenu::OnButton(uint8_t button) {
    if(button == 0 || button == 1){
        alarmManager.Stop();
        Manager.MoveTo(menu);
    } else if (button == 2 || button == 3){
        alarmManager.Snooze();
        Manager.MoveTo(menu);
    }
    buzzer.SetBuzzer(false);
}


