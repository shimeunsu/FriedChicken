#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Chicken.hpp"
#include "Human.hpp"
#include "DEFINITIONS.hpp"

class Game{

public:
    Game();
    void Loop();
    void initHumans();

private:
    sf::RenderWindow* r;
    Chicken* chicken;

    std::vector<Human*> humans;
};
