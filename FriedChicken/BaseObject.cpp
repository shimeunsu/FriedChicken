
#include "BaseObject.hpp"
using namespace sf;

BaseObject::BaseObject(){

}
void BaseObject::draw(RenderWindow* r){
    r->draw(sprite);
}
Sprite BaseObject::getSprite(){
    return sprite;
}
