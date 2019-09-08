#include "alarm_day.hpp"

AlarmDay operator |(AlarmDay a, AlarmDay b)
{
    return static_cast<AlarmDay>(static_cast<int>(a) | static_cast<int>(b));
}

AlarmDay operator &(AlarmDay a, AlarmDay b)
{
    return static_cast<AlarmDay>(static_cast<int>(a) & static_cast<int>(b));
}

AlarmDay operator ^(AlarmDay a, AlarmDay b)
{
    return static_cast<AlarmDay>(static_cast<int>(a) ^ static_cast<int>(b));
}