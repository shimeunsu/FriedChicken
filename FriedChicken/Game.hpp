#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Chicken.hpp"
#include "Human.hpp"
#include "DEFINITIONS.hpp"

/*!
 \brief "Game class header to generate different aspects of the game"
 */
class Game{

public:
    /*!
     \brief "Constructor that creates the game with the window and sprites"
     */
    Game();
    
    /*!
     \brief "Create all the humans"
     */
    void initHumans();
    
    /*!
     \brief "Loop to run the game, listen to events, and run the score"
     */
    void Loop();
    
    /*!
     \brief "Set the title of window"
     \param "Pointer to the window and the score to print"
     */
    void updateTitle(sf::Window* w, int score);
    
    /*!
     \brief "Reset the game when playing again"
     */
    void reset();
    
    /*!
     \brief "Load the game over screen"
     \param "Pointer to the window and the score to print"
     */
    void gameOver(sf::RenderWindow* rWindow);
    
    /*!
     \brief "Load the victory screen"
     \param "Pointer to the window and the score to print"
     */
    void gameWin(sf::RenderWindow* rWindow, int score);

private:
    sf::RenderWindow* rWindow;
    Chicken* chicken;
    sf::Clock* gameClock;
    int score;
    std::vector<Human*> humans;
};
