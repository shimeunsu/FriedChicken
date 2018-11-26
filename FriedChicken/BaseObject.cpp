
#include "BaseObject.hpp"
using namespace sf;

BaseObject::BaseObject(){
    
}
void BaseObject::Draw(RenderWindow &r){
    r.draw(shape);
}
Sprite BaseObject::GetShape(){
    return shape;
}
