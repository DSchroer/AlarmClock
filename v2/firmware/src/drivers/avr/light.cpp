#include "drivers/light.hpp"
#include "io.hpp"

#define LIGHT (1 << 5)

Light::Light(){
    DDRB |= LIGHT;
}

void Light::SetLight(bool turnedOn){
    if (turnedOn)
        PORTB |= LIGHT;
    else
        PORTB &= ~LIGHT;
}



// void update_light(Time &time)
// {
//     static uint8_t remaining = 0;
//     static uint8_t seconds = 0;

//     if (btn_any_pressed())
//     {
//         remaining = 10;
//     }

//     if (seconds != time.seconds)
//     {
//         seconds = time.seconds;

//         if (remaining > 0)
//             remaining--;
//     }

//     if (remaining > 0)
//         set_light(true);
//     else
//         set_light(false);
// }
