
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.hpp"
#include "DEFINITIONS.hpp"

class Chicken : public BaseObject{

public:
    Chicken(sf::Vector2u size);
    void Move(sf::Event e);

};
