#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/*!
 \brief "Base Object class header that acts as a parent object for the chicken and humans"
 */
class BaseObject {
public:
    /*!
     \brief "Constructor that creates the object"
     */
    BaseObject();
    
    /*!
     \brief "Get function that returns the object"
     \return "Return a pointer of the sprite object"
     */
    sf::Sprite* GetShape();
    
protected:
    sf::Sprite* shape;
};
