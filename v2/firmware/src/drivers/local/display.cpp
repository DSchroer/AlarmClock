#include <X11/Xlib.h>
#include <drivers/display.hpp>

// only to keep the main code clean
::Display *d;
int scale = 3;

Alarm::Display::Display() {
    // Open a display.
    d = XOpenDisplay(0);

    if (d) {
        // Create the window
        Window w = XCreateWindow(d, DefaultRootWindow(d), 0, 0, 84 * scale,
                                 48 * scale, 0, CopyFromParent, CopyFromParent,
                                 CopyFromParent, 0, 0);

        // Show the window
        XMapWindow(d, w);
    }
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