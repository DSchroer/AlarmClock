#pragma once

#include "../time.hpp"

class Clock {
  private:
  public:
    Clock();

    void GetTime(Time &time);
    void SetTime(Time &time);
};