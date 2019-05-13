#include "../utils/menu_manager.hpp"

class MainMenu: public Menu
{
public:
    MainMenu(MenuManager& manager): Menu(manager) {};

    void Render(Display& display);
};