#pragma once

#include "../time.hpp"

class Clock {
  private:
  public:
    Clock();
    Time time;

    void Tick();
    void SetTime(Time &time);
};