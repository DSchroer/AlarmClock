#include <drivers/display.hpp>

extern "C" {
#include <nokia5110.h>
}

Display::Display() {
    nokia_lcd_init();
    Clear();
}

Display::~Display() {
}

void Display::SetCursor(int x, int y) {
    nokia_lcd_set_cursor(x, y);
}

void Display::Write(const char *message, int scale) {
    nokia_lcd_write_string(message, scale);
}

void Display::Write(char character, int scale) {
    nokia_lcd_write_char(character, scale);
}

void Display::Pixel(int x, int y) {
    nokia_lcd_set_pixel(x, y, 1);
}

void Display::Flush() {
    nokia_lcd_render();
}

void Display::Clear() {
    nokia_lcd_clear();
}