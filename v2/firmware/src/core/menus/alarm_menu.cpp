#include "alarm_menu.hpp"

void AlarmMenu::Render(Display &display) {
    light.SetLight(true);
    buzzer.SetBuzzer(clock.time.seconds % 3 == 0);

    if(lastSecond != clock.time.seconds){
        lastSecond = clock.time.seconds;
        alarmTime++;
    }

    if(alarmTime > CUTOFF_TIME){
        alarmManager.Stop();
        Manager.MoveTo(menu);
        buzzer.SetBuzzer(false);
    }

    display.SetCursor(5,5);
    display.Write("Good Morning!");

    display.SetCursor(9, 20);
    display.Write("^ Stop");

    display.SetCursor(9, 30);
    display.Write("~ Snooze");
}

void AlarmMenu::OnButton(uint8_t button) {
    if(button == 1){
        alarmManager.Stop();
        Manager.MoveTo(menu);
        buzzer.SetBuzzer(false);
    } else if (button == 2){
        alarmManager.Snooze();
        Manager.MoveTo(menu);
        buzzer.SetBuzzer(false);
    }
}

void AlarmMenu::Reset() {
    Menu::Reset();

    lastSecond = 0;
    alarmTime = 0;
}


