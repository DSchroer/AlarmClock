#pragma once

#include "./alarm_registry.hpp"
#include "../utils/heap.hpp"
#include "../utils/vector.hpp"

#include <drivers/rtc.hpp>

struct AlarmEntry {
    Alarm alarm{};
    bool isSnoozed = false;

    explicit AlarmEntry(Alarm value, bool snooze = false): alarm{value}, isSnoozed{snooze} { }
};

class AlarmManager{
private:
    Vector<Alarm>& registry;
    Vector<AlarmEntry> alarms{};
    AlarmEntry* activeAlarm = nullptr;
public:
    explicit AlarmManager(Vector<Alarm>& registry): registry{registry} { Rebuild(); };

    bool Test(Time& time);
    void Snooze();
    void Stop();
    void Rebuild();
};