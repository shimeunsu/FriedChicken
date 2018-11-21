
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.hpp"
#include "DEFINITIONS.hpp"
using namespace sf;

class Human:public BaseObject{
    
public:
    Human(float posX, float posY);
    void Move(Vector2u size);
    
private:
    float originalPosX, originalPosY;
    
    
};
