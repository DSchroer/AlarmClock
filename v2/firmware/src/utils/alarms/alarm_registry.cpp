#include "./alarm_registry.hpp"

#include <stdlib.h> 

AlarmRegistry::AlarmRegistry() {
    alarms = (Alarm*)malloc(0);
    length = 0;
}

AlarmRegistry::~AlarmRegistry(){
    free(alarms);
}

Alarm& AlarmRegistry::Create(){
    length++;
    alarms = (Alarm*)realloc(alarms, sizeof(Alarm) * length);
    return alarms[length - 1];
}

Alarm& AlarmRegistry::operator[] (const uint8_t index){
    return alarms[index];
}

void AlarmRegistry::Remove(const uint8_t index){
    if(length <= index){
        return;
    }

    alarms[index] = alarms[length -1];
    length--;
    alarms = (Alarm*)realloc(alarms, sizeof(Alarm) * length);
}

uint8_t AlarmRegistry::Count(){
    return length;
}