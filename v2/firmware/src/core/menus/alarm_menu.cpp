#include <utils/menu_utils.hpp>
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

    DrawTime(display, clock.time);

    display.SetCursor(15, 25);
    display.Write("^ Stop");

    display.SetCursor(15, 35);
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


