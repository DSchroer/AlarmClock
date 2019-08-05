#include "gtest/gtest.h"
#include "alarms/alarm_manager.hpp"

TEST(AlarmTests, TestAlarms) {
    Vector<Alarm> alarms{};
    alarms.Add(Alarm(0,0, AlarmDay::All));
    AlarmManager manager{alarms};

    Time time{};
    time.minutes = 0;
    time.hours = 0;

    ASSERT_TRUE(manager.Test(time));
}

TEST(AlarmTests, TestSnooze) {
    Vector<Alarm> alarms{};
    alarms.Add(Alarm(0,0, AlarmDay::All));
    AlarmManager manager{alarms};

    Time time{};
    time.minutes = 0;
    time.hours = 0;

    ASSERT_TRUE(manager.Test(time));

    manager.Snooze();
    time.seconds = 1;
    ASSERT_FALSE(manager.Test(time));

    time.minutes = 10;
    time.seconds = 0;

    ASSERT_TRUE(manager.Test(time));
}

TEST(AlarmTests, TestStop) {
    Vector<Alarm> alarms{};
    alarms.Add(Alarm(0,0, AlarmDay::All));
    AlarmManager manager{alarms};

    Time time{};
    time.minutes = 0;
    time.hours = 0;

    ASSERT_TRUE(manager.Test(time));

    manager.Stop();
    time.seconds = 1;
    ASSERT_FALSE(manager.Test(time));
}