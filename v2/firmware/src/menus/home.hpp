#include "../utils/menu_manager.hpp"
#include "drivers/rtc.hpp"

class Home: public Menu
{
private:
    Clock& _clock;
    Menu& _main_menu;

public:
    Home(MenuManager& manager, Clock& clock, Menu& mainMenu): 
        Menu(manager), _clock(clock), _main_menu(mainMenu) {};

    void Render(Display& display);
    void OnButton(uint8_t button);
};