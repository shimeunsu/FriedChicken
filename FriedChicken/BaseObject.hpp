#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Chicken.hpp"
#include "Chicken.cpp"
#include "Human.hpp"
#include "Human.cpp"

class BaseObject{
public:
    BaseObject();
    void Draw(RenderWindow &r);
    RectangleShape GetShape();
protected:
    RectangleShape shape;
    
};
