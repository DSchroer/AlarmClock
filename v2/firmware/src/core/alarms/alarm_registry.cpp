#include "./alarm_registry.hpp"

#define SIZE_ADDR (void *)0x00
#define DATA_ADDR (void *)0x01

void AlarmRegistry::Save() {
    storage.Save(SIZE_ADDR, &this->Count, sizeof(this->Count));
    storage.Save(DATA_ADDR, this->data, this->Count * sizeof(Alarm));
}

void AlarmRegistry::Load() {
    storage.Load(SIZE_ADDR, &this->Count, sizeof(this->Count));
    if(this->Count == 255){
        this->Count = 0;
    }

    Resize();
    storage.Load(DATA_ADDR, this->data, this->Count * sizeof(Alarm));
}
