#include <iostream>
#include <SFML/Graphics.hpp>
#include "Chicken.hpp"
using namespace sf;

Chicken::Chicken(Vector2u size){
    shape.setSize(Vector2f(CHICKEN_SIZE_WIDTH,CHICKEN_SIZE_HEIGHT));
    shape.setPosition(Vector2f(shape.getPosition().x, size.y - shape.getSize().y));
}

void Chicken::Move(Event e){
    if(Keyboard::Key::Right == e.key.code){
        if(shape.getPosition().x <= 1920 - CHICKEN_SIZE_WIDTH && shape.getPosition().x >= 0 - CHICKEN_SIZE_WIDTH ){
        shape.move(CHICKEN_MOVEMENT_AMOUNT,0);
        }
    }
    else if(Keyboard::Key::Left == e.key.code){
         if(shape.getPosition().x <= 1920 - CHICKEN_SIZE_WIDTH && shape.getPosition().x >= 0 - CHICKEN_SIZE_WIDTH ){
        shape.move(-CHICKEN_MOVEMENT_AMOUNT,0);
         }
    }
    else if(Keyboard::Key::Up == e.key.code){
         if(shape.getPosition().x <= 1080 - CHICKEN_SIZE_WIDTH && shape.getPosition().x >= 0 - CHICKEN_SIZE_WIDTH ){
        shape.move(0,-CHICKEN_MOVEMENT_AMOUNT);
         }
    }
    else if(Keyboard::Key::Down == e.key.code){
         if(shape.getPosition().x <= 1080 - CHICKEN_SIZE_WIDTH && shape.getPosition().x >= 0 - CHICKEN_SIZE_WIDTH ){
        shape.move(0,CHICKEN_MOVEMENT_AMOUNT);
    }
    }
    
    
}

