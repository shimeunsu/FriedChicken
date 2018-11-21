#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class BaseObject{
public:
    BaseObject();
    void Draw(RenderWindow &r);
    RectangleShape GetShape();
protected:
    RectangleShape shape;
    
};
