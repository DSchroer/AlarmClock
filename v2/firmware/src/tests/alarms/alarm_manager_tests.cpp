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