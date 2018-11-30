#include "BaseObject.hpp"

using namespace sf;

/*!
 \brief "Base Object class header that acts as a parent object for the chicken and humans"
 */
BaseObject::BaseObject() {}

/*!
 \brief "Get function that returns the object"
 \return "Return a pointer of the sprite object"
 */
Sprite* BaseObject::GetShape(){
    return shape;
}
