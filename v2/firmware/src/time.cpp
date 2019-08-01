#include "../drivers/include/time.hpp"

bool operator >(const Time& lhs, const Time& rhs) {
    return 
        lhs.year > rhs.year         || (lhs.year == rhs.year &&
        lhs.month > rhs.month       || (lhs.month == rhs.month &&
        lhs.date > rhs.date         || (lhs.date == rhs.date &&
        lhs.hours > rhs.hours       || (lhs.hours == rhs.hours &&
        lhs.minutes > rhs.minutes   || (lhs.minutes == rhs.minutes &&
        lhs.seconds > rhs.seconds   || (lhs.seconds == rhs.seconds
        ))))));
}

bool operator <(const Time& lhs, const Time& rhs) {
    return rhs > lhs;
}

bool operator ==(const Time& lhs, const Time& rhs) {
    return 
        lhs.seconds == rhs.seconds && 
        lhs.minutes == rhs.minutes &&
        lhs.hours == rhs.hours &&
        lhs.date == rhs.date &&
        lhs.month == rhs.month &&
        lhs.year == rhs.year;
}