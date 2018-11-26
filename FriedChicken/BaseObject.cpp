
#include "BaseObject.hpp"
using namespace sf;

BaseObject::BaseObject(){
    
}
void BaseObject::Draw(RenderWindow &r){
    r.draw(shape);
}
RectangleShape BaseObject::GetShape(){
    return shape;
}
