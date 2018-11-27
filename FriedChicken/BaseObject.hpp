#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class BaseObject {
public:
    BaseObject();
    sf::Sprite* GetShape();
protected:
    sf::Sprite* shape;

};
