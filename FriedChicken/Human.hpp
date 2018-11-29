#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.hpp"
#include "DEFINITIONS.hpp"

class Human: public BaseObject{

public:
    /*!
     \brief "Constructor that creates the human"
     \param "X and Y coordinates of the position"
     */
    Human(float posX, float posY);
    
    /*!
     \brief "Move the human down"
     \param "The size of the window"
     */
    void MoveDown(sf::Vector2u size, float speed);
    
    /*!
     \brief "Move the human up"
     \param "The size of the window"
     */
    void MoveUp(sf::Vector2u size);

private:
    float originalPosX, originalPosY;
    float speed;
};
