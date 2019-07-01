#include "../utils/menu_manager.hpp"
#include "drivers/rtc.hpp"

class MainMenu: public Menu
{
private:
    
public:
    Menu* home;

    MainMenu(MenuManager& manager): Menu(manager) {};

    void Render(Display& display);
    void OnButton(uint8_t button);
};