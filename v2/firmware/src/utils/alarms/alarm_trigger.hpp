#pragma once

#include "./alarm_registry.hpp"
#include "../heap.hpp"

#include <drivers/rtc.hpp>

struct Trigger
{
    Time next;
    bool isSnooze;
    Alarm& alarm;
};

bool operator >(const Trigger& lhs, const Trigger& rhs) {
    return lhs.next > rhs.next;
}

bool operator <(const Trigger& lhs, const Trigger& rhs) {
    return lhs.next < rhs.next;
}

bool operator ==(const Trigger& lhs, const Trigger& rhs) {
    return lhs.next == rhs.next;
}

class AlarmTrigger{
private:
    AlarmRegistry& registry;
    Heap<Trigger> triggers;

public:
    AlarmTrigger(AlarmRegistry& registry);
    ~AlarmTrigger();

    bool Test(Time& time);
    void Snooze();
    void Rebuild();
};