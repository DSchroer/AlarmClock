#pragma once

#include <drivers/storage.hpp>
#include "./alarm.hpp"
#include "../utils/vector.hpp"

class AlarmRegistry: public Vector<Alarm>
{
private:
    Storage& storage;
public:
    AlarmRegistry(Storage& storage): storage{storage} {};

    void Save();
    void Load();
};
