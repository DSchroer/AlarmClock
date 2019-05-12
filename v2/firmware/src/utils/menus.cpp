// #include "menus.hpp"

// #include <stdio.h>

// // #include "rtc.hpp"
// // #include "nokia.hpp"
// // #include "menu_utils.hpp"

// void draw_time(Time &time)
// {
//     // char display[16];

//     // nokia_lcd_clear();

//     // nokia_lcd_set_cursor(5, 0);
//     // sprintf(display, "% 2d:%02d", time.hours, time.minutes);
//     // nokia_lcd_write_string(display, 2);

//     // nokia_lcd_set_cursor(nokia_lcd_x() + 1, nokia_lcd_y() + 7);
//     // sprintf(display, "%02d", time.seconds);
//     // nokia_lcd_write_string(display, 1);

//     // draw_line(17);

//     // nokia_lcd_set_cursor(0, 20);
//     // sprintf(display, "%s %d%s", days[time.day - 1], time.date, rtc_ordinal(time.date));
//     // nokia_lcd_write_string(display, 1);

//     // nokia_lcd_set_cursor(0, 30);
//     // sprintf(display, "%s 20%02d", months[time.month - 1], time.year);
//     // nokia_lcd_write_string(display, 1);

//     // nokia_lcd_set_cursor(0, 40);
//     // sprintf(display, "Alarm at 00:00");
//     // nokia_lcd_write_string(display, 1);

//     // nokia_lcd_render();
// }

// void draw_main_menu()
// {
//     // nokia_lcd_clear();

//     // nokia_lcd_write_string("Main Menu", 1);
//     // nokia_lcd_set_cursor(0, 20);

//     // const char *options[] = {"Alarms", "Time", "Cancel"};
//     // static unsigned int option_menu_pos;

//     // if (draw_options_menu(option_menu_pos, options, 3))
//     // {
//     //     switch (option_menu_pos)
//     //     {
//     //     case 0:
//     //         break;
//     //     case 1:
//     //         break;
//     //     case 2:
//     //         menu_state = MenuState::DISPLAY_TIME;
//     //         break;
//     //     }
//     // }

//     // nokia_lcd_render();
// }