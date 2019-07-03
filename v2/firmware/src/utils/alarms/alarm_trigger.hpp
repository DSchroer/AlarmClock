#pragma once

#include "./alarm_registry.hpp"

#include <drivers/rtc.hpp>

struct Trigger
{
    Time next;
    bool isSnooze;
    Alarm& alarm;
};

class AlarmTrigger{
private:
    AlarmRegistry& registry;
    Trigger* triggers;

    uint8_t Parent(const uint8_t index);
    uint8_t LChild(const uint8_t index);
    uint8_t RChild(const uint8_t index);

    void BubbleUp();
    void BubbleDown();
public:
    AlarmTrigger(AlarmRegistry& registry);
    ~AlarmTrigger();

    bool Test(Time& time);
    void Snooze();
    void Rebuild();
};