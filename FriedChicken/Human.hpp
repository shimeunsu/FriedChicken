#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.hpp"
#include "DEFINITIONS.hpp"

class Human:public BaseObject{

public:
    Human(float posX, float posY);
    void MoveDown(sf::Vector2u size);
    void MoveUp(sf::Vector2u size);

private:
    float originalPosX, originalPosY;
};
