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
    void updateTitle(sf::Window* w, int score);
    void Game::reset();

private:
    sf::RenderWindow* r;
    Chicken* chicken;
    sf::Clock* gameClock;
    int score;

    std::vector<Human*> humans;
};
