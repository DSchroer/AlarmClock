#include <drivers/rtc.hpp>

#include <ctime>

Clock::Clock(){
    Tick();
}

void Clock::Tick(){
    auto newTime = std::time(NULL);
    auto fullTime = localtime(&newTime);

    time.hours = fullTime->tm_hour;
    time.minutes = fullTime->tm_min;
    time.seconds = fullTime->tm_sec;

    time.date = fullTime->tm_mday;
    time.day = fullTime->tm_wday;

    time.month = fullTime->tm_mon + 1;
    time.year = 0;

}

void Clock::SetTime(Time& time){

}