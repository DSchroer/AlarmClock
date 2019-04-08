#define F_CPU 800000UL

#ifdef EDITOR
#include <avr/iom328p.h>
#endif

#include <util/delay.h>
#include "utils/rtc.hpp"

void initialize();
void update(Time &time);