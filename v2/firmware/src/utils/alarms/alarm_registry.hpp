#pragma once

#include "./alarm.hpp"

class AlarmRegistry
{
private:
    Alarm* alarms;
    uint8_t length;
public:
    AlarmRegistry();
    ~AlarmRegistry();

    Alarm& Create();
    Alarm& operator[] (const uint8_t index);
    void Remove(const uint8_t index);
    uint8_t Count();
};
