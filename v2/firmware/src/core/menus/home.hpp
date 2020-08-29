#include <drivers/light.hpp>
#include "../utils/menu_manager.hpp"
#include "drivers/rtc.hpp"

class Home: public Menu
{
private:
    Clock& clock;
    Menu& mainMenu;
    Light& light;

public:
    Home(MenuManager& manager, Clock& clock, Menu& mainMenu, Light& light):
            Menu(manager), clock(clock), mainMenu(mainMenu), light{light} {};

    void Render(Display& display);
    void OnButton(uint8_t button);
};