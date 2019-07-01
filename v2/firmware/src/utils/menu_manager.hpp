#pragma once
#include <display.hpp>

class Menu;

class MenuManager
{
private:
    Menu* current;
public:
    MenuManager() {};

    void MoveTo(Menu& menu);
    void Update();
    void Render(Display& display);
};

class Menu
{
protected:
    MenuManager& Manager;

public:
    Menu(MenuManager& manager): Manager{manager} {};

    virtual void Reset() {};
    virtual void Update() {};
    virtual void Render(Display& display) = 0;
    virtual void OnButton(uint8_t button) {};
};