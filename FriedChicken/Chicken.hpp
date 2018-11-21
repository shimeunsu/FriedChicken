#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Chicken{
    
public:
    Chicken(Vector2u size);
    void Draw(RenderWindow &r);
    void Move(Event e);
    
    RectangleShape GetShape();

private:
    RectangleShape chicken;
    
    
};
