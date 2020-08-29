#include <drivers/buttons.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <stdbool.h>

Button::Button() {

}

void Button::Tick() {
}

bool Button::Pressed(uint8_t index) {

    bool pressed = false;
    if (index == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        pressed = true;
    }

    if (index == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        pressed = true;
    }

    if (index == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        pressed = true;
    }

    if (index == 3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        pressed = true;
    }

    return pressed;
}

bool Button::Any() {
    return Pressed(0) || Pressed(1) || Pressed(2) || Pressed(3);
}