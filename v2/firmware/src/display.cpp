#include "display.hpp"
#include "utils/chars.hpp"

#ifdef LOCAL 
#define pgm_read_byte(a) *a
#endif

void Display::SetCursor(uint8_t x, uint8_t y) {
	X = x;
	Y = y;
}

void Display::WriteL(const char *message, uint8_t length, uint8_t scale) {
    while (*message && length--)
		Write(*message++, scale);
}

void Display::Write(const char *message, uint8_t scale) {
    while (*message)
		Write(*message++, scale);
}

void Display::Write(char code, uint8_t scale) {
	for (uint8_t x = 0; x < 5 * scale; x++)
    {
        for (uint8_t y = 0; y < 7 * scale; y++)
        {
            if (pgm_read_byte(&CHARSET[code - 32][x / scale]) & (1 << y / scale)){
                Pixel(X + x, Y + y, 1);
            } else {
                Pixel(X + x, Y + y, 0);
            }	
        }	
    }
	
	X += 5 * scale + 1;
	if (X >= 84)
	{
		X = 0;
		Y += 7 * scale + 1;
	}
	if (Y >= 48)
	{
		X = 0;
		Y = 0;
	}
}

void Display::Line(uint8_t y){
	Line(0, y, 84);
}

void Display::Line(uint8_t x, uint8_t y, uint8_t length){
	for (int xPos = x; xPos < x + length; xPos++)
	{
		Pixel(xPos, y, 1);
	}
}