#include "../utils/menu_manager.hpp"
#include "drivers/rtc.hpp"

class Home: public Menu
{
private:
    Clock& _clock;

public:
    Home(MenuManager& manager, Clock& clock): Menu(manager), _clock(clock) {};

    void Render(Display& display);
    void OnButton(uint8_t button);
};