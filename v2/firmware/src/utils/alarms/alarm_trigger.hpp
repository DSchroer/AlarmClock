#pragma once

#include "./alarm_registry.hpp"
#include "../heap.hpp"
#include "../vector.hpp"

#include <drivers/rtc.hpp>

struct AlarmEntry {
    Alarm alarm;
    bool isSnoozed = false;

    AlarmEntry(Alarm value) { this->alarm = value; }
};

class AlarmManager{
private:
    Vector<Alarm>& registry;
    Vector<AlarmEntry> alarms{};
    AlarmEntry* activeAlarm = nullptr;
public:

    bool Test(Time& time);
    void Snooze();
    void Stop();
    void Rebuild();
};