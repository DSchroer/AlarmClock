#include "../utils/menu_manager.hpp"
#include "drivers/rtc.hpp"

class SetTime: public Menu
{
private:
    Clock& clock;
    Time editTime;

public:
    SetTime(MenuManager& manager, Clock& clock): Menu(manager), clock{clock} {};

    void Render(Display& display);
    void OnButton(uint8_t button);
    void Reset();
};