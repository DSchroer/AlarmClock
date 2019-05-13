#include "main_menu.hpp"

void MainMenu::Render(Display& display){
    display.SetCursor(10,2);
    display.Write("Main Menu!");
    display.Line(15);
}