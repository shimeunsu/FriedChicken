#include "BaseObject.hpp"

using namespace sf;

/*!
 \brief "Parent object class for Chicken and Human"
 \param "none"
 */
BaseObject::BaseObject() {}

/*!
 \brief "Return a sprite pointer"
 \param "none"
 */
Sprite* BaseObject::GetShape(){
    return shape;
}
