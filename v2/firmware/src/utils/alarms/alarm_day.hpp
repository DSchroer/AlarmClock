#pragma once

enum class AlarmDay {
    None        = 0x00,
    Monday      = 0x01,
    Tuesday     = 0x02,
    Wednesday   = 0x04,
    Thursday    = 0x08,
    Friday      = 0x10,
    Saturday    = 0x20,
    Sunday      = 0x40
};

inline AlarmDay operator |(AlarmDay a, AlarmDay b)
{
    return static_cast<AlarmDay>(static_cast<int>(a) | static_cast<int>(b));
}

inline AlarmDay operator &(AlarmDay a, AlarmDay b)
{
    return static_cast<AlarmDay>(static_cast<int>(a) & static_cast<int>(b));
}