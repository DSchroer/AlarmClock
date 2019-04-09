#pragma once

class Display
{
public:
    Display();
    ~Display();

    int x;
    int y;

    void SetCursor(int x, int y);
    void Write(const char * message, int scale);
    void Write(char character, int scale);
    void Pixel(int x, int y);
    void Clear();
};
