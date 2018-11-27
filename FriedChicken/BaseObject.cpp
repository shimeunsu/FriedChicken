#include "BaseObject.hpp"
using namespace sf;

BaseObject::BaseObject() {}

Sprite* BaseObject::GetShape(){
    return shape;
}
