
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.hpp"
#include "BaseObject.cpp"
#include "DEFINITIONS.hpp"
using namespace sf;

class Chicken : public BaseObject{
    
public:
    Chicken(Vector2u size);
    void Move(Event e);
    
};
