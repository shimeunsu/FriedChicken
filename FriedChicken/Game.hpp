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
    void gameOver(sf::RenderWindow* r, int score);

private:
    sf::RenderWindow* r;
    Chicken* chicken;
    sf::Clock* gameClock;
    int score;

    std::vector<Human*> humans;
};
