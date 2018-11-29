#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/*!
 \brief "Base Object class header"
 \param "none"
 */
class BaseObject {
public:
    /*!
     \brief "Constructor that creates the object"
     \param "none"
     */
    BaseObject();
    
    /*!
     \brief "Return a pointer of the sprite object"
     \param "none"
     */
    sf::Sprite* GetShape();
    
protected:
    sf::Sprite* shape;
};
