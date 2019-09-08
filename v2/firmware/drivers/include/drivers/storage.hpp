#pragma once

#include <stdlib.h>

class Storage {
public:
    Storage();

    void Save(void* address, void * data, size_t size);
    void Load(void* address, void * data, size_t size);
};