
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Human{
    
public:
    Human(float posX, float posY);
    void Draw(RenderWindow &r);
    void Move(Vector2u size);
    RectangleShape GetShape();
    
private:
    RectangleShape human;
    float originalPosX, originalPosY;
    
    
};
