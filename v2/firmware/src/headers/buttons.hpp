#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void btn_init();
void btn_update();
bool btn_any_pressed();
bool btn_pressed(uint8_t number);

class Button
{
public:
    Button(uint8_t index);

    bool Pressed();
};

class ButtonGroup
{
private:
    /* data */
public:
    ButtonGroup(/* args */);
    ~ButtonGroup();

    void Tick();
};

ButtonGroup::ButtonGroup(/* args */)
{
}

ButtonGroup::~ButtonGroup()
{
}
