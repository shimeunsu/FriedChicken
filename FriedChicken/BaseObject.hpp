#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class BaseObject{
public:
    BaseObject();
    void draw(RenderWindow* r);
    Sprite getSprite();
protected:
    Sprite sprite;

};
