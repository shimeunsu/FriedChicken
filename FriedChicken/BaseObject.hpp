#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class BaseObject{
public:
    BaseObject();
    void Draw(sf::RenderWindow &r);
    sf::Sprite GetShape();
protected:
    sf::Sprite shape;
    
};
