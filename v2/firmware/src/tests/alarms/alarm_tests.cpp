#include "gtest/gtest.h"
#include "alarms/alarm.hpp"

TEST(AlarmTests, AddMinutes) {
    Alarm alarm{0,0};

    Alarm next = alarm + 10;
    ASSERT_EQ(10, next.minute);
    ASSERT_EQ(0, next.hour);
}

TEST(AlarmTests, OverflowMinutes) {
    Alarm alarm{50,0};

    Alarm next = alarm + 10;
    ASSERT_EQ(0, next.minute);
    ASSERT_EQ(1, next.hour);
}

TEST(AlarmTests, OverflowDay) {
    Alarm alarm{50,23};

    Alarm next = alarm + 10;
    ASSERT_EQ(0, next.minute);
    ASSERT_EQ(0, next.hour);
}

TEST(AlarmTests, AlarmDayTests) {
    ASSERT_EQ(AlarmDay::Monday, static_cast<AlarmDay>(1 << 0));
    ASSERT_EQ(AlarmDay::Tuesday, static_cast<AlarmDay>(1 << 1));
    ASSERT_EQ(AlarmDay::Wednesday, static_cast<AlarmDay>(1 << 2));
    ASSERT_EQ(AlarmDay::Thursday, static_cast<AlarmDay>(1 << 3));
    ASSERT_EQ(AlarmDay::Friday, static_cast<AlarmDay>(1 << 4));
    ASSERT_EQ(AlarmDay::Saturday, static_cast<AlarmDay>(1 << 5));
    ASSERT_EQ(AlarmDay::Sunday, static_cast<AlarmDay>(1 << 6));
}

TEST(AlarmTests, AlarmEqualTime) {
    Alarm alarm{1,1};
    alarm.days = AlarmDay::All;

    Time time{};
    time.seconds = 0;
    time.minutes = 1;
    time.hours = 1;
    time.day = 1;

    ASSERT_TRUE(alarm == time);
}

TEST(AlarmTests, AlarmNoDay) {
    Alarm alarm{1,1};
    alarm.days = AlarmDay::None;

    Time time{};
    time.seconds = 0;
    time.minutes = 1;
    time.hours = 1;
    time.day = 1;

    ASSERT_FALSE(alarm == time);
}

