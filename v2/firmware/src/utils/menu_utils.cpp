#include "../headers/display.hpp"
#include "../headers/buttons.hpp"

void draw_line(Display& display, uint8_t y)
{
    for (uint8_t x = 0; x < 84; x++)
    {
        display.Pixel(x, y);
    }
}

bool draw_options_menu(Display& display, uint8_t &position, const char **options, uint8_t length)
{
    if (btn_pressed(0))
        position = position + 1;

    if (btn_pressed(1))
    {
        if (position == 0)
        {
            position = length - 1;
        }
        else
        {
            position = position - 1;
        }
    }

    position = position % length;

    uint8_t y = display.y;
    for (uint8_t i = 0; i < length; i++)
    {
        display.SetCursor(0, y + (10 * i));
        if (position == i)
        {
            display.Write('-', 1);
        }

        display.SetCursor(8, display.y);
        display.Write(options[i], 1);
    }

    return btn_pressed(3);
}