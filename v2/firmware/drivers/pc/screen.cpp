#include <drivers/screen.hpp>
#include <SFML/Graphics.hpp>

#include "unistd.h"

sf::RenderWindow window;
sf::Image buffer;
sf::Texture texture;   
sf::Sprite sprite; 

int scale = 10;

Screen::Screen() {
    window.create(sf::VideoMode(84 * scale, 48 * scale), "Clock", sf::Style::Titlebar | sf::Style::Close);
    
    Clear();
}

Screen::~Screen() {
}

void Screen::Flush() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            exit(0);
        }    
    }
  
    texture.loadFromImage(buffer);
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(scale, scale));

    window.draw(sprite);
    window.display();

    usleep(100000);
}

void Screen::Pixel(uint8_t x, uint8_t y, uint8_t value){
    if(value){
        buffer.setPixel(x,y,sf::Color::Black);
    }else{
        buffer.setPixel(x,y,sf::Color::White);
    }
}

void Screen::Clear() {
    buffer.create(84,48,sf::Color::White);
}