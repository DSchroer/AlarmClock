#include "./set_time.hpp"
#include "../utils/menu_utils.hpp"

enum class TimeState {
    HOURS,
    MINUTES,
    SECONDS,
    DAY,
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
    case TimeState::MONTH : return state = TimeState::DAY;
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
    case TimeState::DAY : return state = TimeState::MONTH;
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
        Blink(display, 0, 10, 20);
        break;
    case TimeState::MONTH:
        Blink(display, 0, 10, 20);
        break;
    case TimeState::YEAR:
        Blink(display, 0, 10, 20);
        break;
    case TimeState::REVIEW:
        Blink(display, 0, 10, 20);
        break;

    default:
        Title(display, "ERR");
        break;
    }
}

void SetTime::Reset(){
    editTime = clock.time;
}

void SetTime::OnButton(uint8_t button){
    if(button == 0){
        --EditorState;
    }

    if(button == 3){
        ++EditorState;
    }
}