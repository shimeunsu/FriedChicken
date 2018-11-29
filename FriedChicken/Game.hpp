#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Chicken.hpp"
#include "Human.hpp"
#include "DEFINITIONS.hpp"

class Game{

public:
    /*!
     \brief "Constructor that creates the game with the window and sprites"
     \param "none"
     */
    Game();
    
    /*!
     \brief "Create all the humans"
     \param "none"
     */
    void initHumans();
    
    /*!
     \brief "Loop to run the game, listen to events, and run the score"
     \param "none"
     */
    void Loop();
    
    /*!
     \brief "Set the title of window"
     \param "Pointer to the window and the score to print"
     */
    void updateTitle(sf::Window* w, int score);
    
    /*!
     \brief "Reset the game when playing again"
     \param "none"
     */
    void reset();
    
    /*!
     \brief "Load the game over screen"
     \param "Pointer to the window and the score to print"
     */
    void gameOver(sf::RenderWindow* r);
    
    /*!
     \brief "Load the victory screen"
     \param "Pointer to the window and the score to print"
     */
    void gameWin(sf::RenderWindow* r, int score);

private:
    sf::RenderWindow* r;
    Chicken* chicken;
    sf::Clock* gameClock;
    int score;
    std::vector<Human*> humans;
};
