#include <drivers/buttons.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <stdbool.h>

Button::Button() {

}

void Button::Tick() {

}

bool Button::Pressed(uint8_t index) {

    if(index == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)){
        return true;
    }

    if(index == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)){
        return true;
    }

    if(index == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)){
        return true;
    }

    if(index == 3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)){
        return true;
    }

    return false;
}

bool Button::Any() {
    return Pressed(0) || Pressed(1) || Pressed(2) || Pressed(3);
}