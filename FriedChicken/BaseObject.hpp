#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class BaseObject{
public:
    BaseObject();
    void Draw(RenderWindow &r);
    RectangleShape GetShape();
protected:
    RectangleShape shape;
    
};
