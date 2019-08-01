#include "./alarm_trigger.hpp"

bool AlarmManager::Test(Time &time) {
    if(activeAlarm != nullptr){
        return true;
    }

    for(uint8_t i = 0; i < alarms.Count; i++){
        auto entry = alarms[i];
        if(entry.alarm == time){
            activeAlarm = &alarms[i];
            return true;
        }
    }

    return false;
}

void AlarmManager::Snooze() {
    if(activeAlarm == nullptr){
        return;
    }
}

void AlarmManager::Rebuild() {
    activeAlarm = nullptr;
    alarms.Clear();

    for(uint8_t i = 0; i < registry.Count; i++){
        auto alarm = registry[i];
        if(alarm.enabled){
            alarms.Add(AlarmEntry{alarm});
        }
    }
}

void AlarmManager::Stop() {
    if(activeAlarm->isSnoozed){

    }
    activeAlarm = nullptr;
}
