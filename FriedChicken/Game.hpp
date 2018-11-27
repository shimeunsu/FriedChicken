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
    void gameOver(RenderWindow* r, int score);

private:
    sf::RenderWindow* r;
    Chicken* chicken;
    sf::Clock* gameClock;

    std::vector<Human*> humans;
};
