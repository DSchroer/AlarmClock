#include "alarm_manager.hpp"

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

    alarms.Add(AlarmEntry(activeAlarm->alarm + 10, true));
    activeAlarm = nullptr;
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
    if(activeAlarm == nullptr){
        return;
    }

    if(activeAlarm->isSnoozed){
        auto index = alarms.IndexOf(activeAlarm);
        if(index != -1){
            alarms.Remove(index);
        }else{
            Rebuild();
        }
    }

    activeAlarm = nullptr;
}
