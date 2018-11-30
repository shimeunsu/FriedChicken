#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BaseObject.hpp"
#include "DEFINITIONS.hpp"

/*!
 \brief "Chicken class header that creates the hero chicken object trying to cross the desert plane"
 \pre "Inherits from Base Object"
 */
class Chicken : public BaseObject{

public:
    /*!
     \brief "Constructor that creates the chicken"
     \return "Chicken object"
     */
    Chicken();
    
    /*!
     \brief "Move the chicken based on the event"
     \param "An event of type Event"
     */
    void Move(sf::Event e);
};
