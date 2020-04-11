#pragma once
#include "../utils/menu_manager.hpp"
#include "../utils/vector.hpp"

class State
{
public:
    virtual void Draw(Display& display) = 0;
    virtual void Click() = 0;
};

class TextState: public State
{
private:
    const char* text;
public:
    TextState(const char* text): text{text} {};

    void Draw(Display& display) override { display.Write(text); };
    void Click() override {};
};

class NavState: public State
{
private:
    const char* text;
    MenuManager& manager;
    Menu& menu;
public:
    NavState(const char* text, MenuManager& manager, Menu& menu): text{text}, manager{manager}, menu{menu} {};

    void Draw(Display& display) override { display.Write(text); };
    void Click() override { manager.MoveTo(menu); };
};

class Option
{
private:
    uint8_t currentState = 0;
    Vector<State*> states;
public:
    explicit Option(Vector<State*> states): states{states} {};
    explicit Option(): states{} {};

    void Reset() { currentState = 0; };
    void Click() { 
        if(states.Count > 0){
            states[currentState]->Click();
        }
    };
    void Draw(Display& display) {
        if(states.Count > 0){
            states[currentState]->Draw(display);
        }
    };
};

class ListMenu: public Menu
{
private:
    const char* title;
    Vector<Option> options;
    uint8_t position = 0;
    Menu* parent = nullptr;
public:
    ListMenu(MenuManager& manager, const char* title, Vector<Option> options): Menu{manager}, title{title}, options{options} {};

    void Render(Display& display) override;
    void OnButton(uint8_t button) override;
    void Reset() override;

    void AddOption(Option option);
    void SetParent(Menu& parent);

    void RenderLine(uint8_t y, uint8_t renderPos, Display &display);
};

