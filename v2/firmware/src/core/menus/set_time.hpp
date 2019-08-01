#include "../utils/menu_manager.hpp"
#include "drivers/rtc.hpp"

class SetTime: public Menu
{
private:
    Clock& clock;
    Time editTime;
    Menu& menu;

public:
    SetTime(MenuManager& manager, Clock& clock, Menu& menu): Menu(manager), clock{clock}, menu{menu} {};

    void Render(Display& display);
    void OnButton(uint8_t button);
    void Reset();
};