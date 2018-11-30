#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.hpp"
#include "DEFINITIONS.hpp"

/*!
 \brief "Human class header that creates a human object as enemies"
 \pre "Inherits from Base Object"
 */
class Human: public BaseObject{

public:
    /*!
     \brief "Constructor that creates the human"
     \param "X and Y coordinates of the position"
     \return "Human object"
     */
    Human(float posX, float posY);
    
    /*!
     \brief "Move the human down"
     \param "The size of the window and takes speed"
     */
    void MoveDown(sf::Vector2u size, float speed);
    
    /*!
     \brief "Move the human up"
     \param "The size of the window and takes speed"
     */
    void MoveUp(sf::Vector2u size, float speed);

private:
    float originalPosX, originalPosY;
    float speed;
};
