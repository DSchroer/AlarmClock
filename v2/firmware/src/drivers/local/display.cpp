#include <drivers/display.hpp>
#include <sfml.h>

Alarm::Display::Display() {
    sf::RenderWindow window(
        sf::VideoMode(84, 48), // size of the client area we want
        "Display an Image"     // The text to appear on the window title
    );
}

Alarm::Display::~Display() {
}

void Alarm::Display::SetCursor(int x, int y) {
}

void Alarm::Display::Write(const char *message, int scale) {
}

void Alarm::Display::Write(char character, int scale) {
}

void Alarm::Display::Pixel(int x, int y) {
}

void Alarm::Display::Flush() {
    XFlush(d);
}

void Alarm::Display::Clear() {
}