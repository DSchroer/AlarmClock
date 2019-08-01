#pragma once

#include "./alarm.hpp"
#include "../vector.hpp"

class AlarmRegistry: Vector<Alarm>
{
private:
public:
    AlarmRegistry();
    ~AlarmRegistry();

    void Save();
    void Load();
};
