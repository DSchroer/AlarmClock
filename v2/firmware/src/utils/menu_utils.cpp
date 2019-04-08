#include "nokia.hpp"
#include "buttons.hpp"

void draw_line(unsigned int y)
{
    for (unsigned int x = 0; x < 84; x++)
    {
        nokia_lcd_set_pixel(x, y, 1);
    }
}

bool draw_options_menu(unsigned int &position, const char **options, unsigned int length)
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

    uint8_t y = nokia_lcd_y();
    for (uint8_t i = 0; i < length; i++)
    {
        nokia_lcd_set_cursor(0, y + (10 * i));
        if (position == i)
        {
            nokia_lcd_write_char('-', 1);
        }

        nokia_lcd_set_cursor(8, nokia_lcd_y());
        nokia_lcd_write_string(options[i], 1);
    }

    return btn_pressed(3);
}