#include "./set_time.hpp"
#include "../utils/menu_utils.hpp"

enum class TimeState {
    HOURS,
    MINUTES,
    SECONDS,
    DAY,
    DATE,
    MONTH,
    YEAR,
    REVIEW
};

TimeState& operator--(TimeState& state)
{
  switch(state) {
    case TimeState::HOURS : return state = TimeState::HOURS;
    case TimeState::MINUTES : return state = TimeState::HOURS;
    case TimeState::SECONDS : return state = TimeState::MINUTES;
    case TimeState::DAY : return state = TimeState::SECONDS;
    case TimeState::DATE : return state = TimeState::DAY;
    case TimeState::MONTH : return state = TimeState::DATE;
    case TimeState::YEAR : return state = TimeState::MONTH;
    case TimeState::REVIEW : return state = TimeState::YEAR;
  }
  return state;
}

TimeState& operator++(TimeState& state)
{
  switch(state) {
    case TimeState::HOURS : return state = TimeState::MINUTES;
    case TimeState::MINUTES : return state = TimeState::SECONDS;
    case TimeState::SECONDS : return state = TimeState::DAY;
    case TimeState::DAY : return state = TimeState::DATE;
    case TimeState::DATE : return state = TimeState::MONTH;
    case TimeState::MONTH : return state = TimeState::YEAR;
    case TimeState::YEAR : return state = TimeState::REVIEW;
    case TimeState::REVIEW : return state = TimeState::REVIEW;
  }
  return state; 
}

static TimeState EditorState {TimeState::HOURS};

void Title(Display& display, const char* title){
        display.Write(title);
}

void Blink(Display& display, uint8_t x, uint8_t y, uint8_t length){
    static bool on = true;
    if(on){
        display.Line(x, y, length);
    }

    on = !on;
}

void SetTime::Render(Display& display){

    DrawTime(display, editTime);
    
    switch (EditorState)
    {
    case TimeState::HOURS:
        Blink(display, 10, 16, 22);
        break;
    case TimeState::MINUTES:
        Blink(display, 42, 16, 22);
        break;
    case TimeState::SECONDS:
        Blink(display, 65, 9, 11);
        break;
    case TimeState::DAY:
        Blink(display, 0, 27, 55);
        break;
    case TimeState::DATE:
        Blink(display, 0, 37, 13);
        break;
    case TimeState::MONTH:
        Blink(display, 18, 37, 55);
        break;
    case TimeState::YEAR:
        Blink(display, 0, 47, 25);
        break;
    case TimeState::REVIEW:
        DrawConfirm(display);
        break;

    default:
        Title(display, "ERR");
        break;
    }
}

void SetTime::Reset(){
    editTime = clock.time;
    EditorState = TimeState::HOURS;
}

void Edit(uint8_t button, uint8_t& value, uint8_t min, uint8_t max){
    if(button == 1){
        ++value;
        if(value >= max){
            value = min;
        }
    }
    if(button == 2){
        if(value <= min){
            value = max;
        }
        --value;
    }
}

void SetTime::OnButton(uint8_t button){
    if(button == 0){
        --EditorState;
    }

    switch (EditorState)
    {
    case TimeState::HOURS:
        Edit(button, editTime.hours, 0, 24);
        break;
    case TimeState::MINUTES:
        Edit(button, editTime.minutes, 0, 60);
        break;
    case TimeState::SECONDS:
        Edit(button, editTime.seconds, 0, 60);
        break;
    case TimeState::DAY:
        Edit(button, editTime.day, 1, 8);
        break;
    case TimeState::DATE:
        Edit(button, editTime.date, 1, 32);
        break;
    case TimeState::MONTH:
        Edit(button, editTime.month, 1, 13);
        break;
    case TimeState::YEAR:
        Edit(button, editTime.year, 0, 100);
        break;
    case TimeState::REVIEW:
        if(button == 1){
            clock.SetTime(editTime);
            Manager.MoveTo(menu);
        }
        if(button == 2){
            Manager.MoveTo(menu);
        }
        break;
    default:
        break;
    }

    if(button == 3){
        ++EditorState;
    }
}