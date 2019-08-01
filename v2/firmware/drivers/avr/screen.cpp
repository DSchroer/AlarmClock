#include <drivers/screen.hpp>

extern "C" {
#include <nokia5110.h>
}

Screen::Screen() {
    nokia_lcd_init();
    Clear();
}

Screen::~Screen() {
}

void Screen::Pixel(uint8_t x, uint8_t y, uint8_t value){
    nokia_lcd_set_pixel(x,y, value);
}

void Screen::Flush() {
    nokia_lcd_render();
}

void Screen::Clear() {
    nokia_lcd_clear();
}