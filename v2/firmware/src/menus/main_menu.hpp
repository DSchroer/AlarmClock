#include "../utils/menu_manager.hpp"
#include "drivers/rtc.hpp"

class MainMenu: public Menu
{
private:
    Clock& _clock;

public:
    MainMenu(MenuManager& manager, Clock& clock): Menu(manager), _clock(clock) {};

    void Render(Display& display);
};