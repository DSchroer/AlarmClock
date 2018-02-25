#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main() {

    DDRD = 0xFF;
    PORTD = 0x00;
    while(1) {
        _delay_ms(1000);
      //  PORTD ^= 1 << 4;
        _delay_ms(100);
        PORTD = 0x00;
    }
    
    return 0;
}