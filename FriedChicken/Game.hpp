#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Chicken.hpp"
#include "Chicken.cpp"
#include "Human.hpp"
#include "Human.cpp"
#include "DEFINITIONS.hpp"

using namespace sf;

class Game{
    
public:
    Game();
    void Loop();
    
private:
    RenderWindow *r;
    Chicken *chicken;
    Human *human;
    Human *human1;
    Human *human2;
    Human *human3;
    Human *human4;
    Human *human5;
};
