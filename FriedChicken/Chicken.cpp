#include <iostream>
#include <SFML/Graphics.hpp>
#include "Chicken.hpp"
using namespace sf;

Chicken::Chicken(Vector2u size){
    shape.setSize(Vector2f(CHICKEN_SIZE_WIDTH,CHICKEN_SIZE_HEIGHT));
    shape.setPosition(Vector2f(shape.getPosition().x, size.y - shape.getSize().y));
}

void Chicken::Move(Event e){
    Vector2f oldPos = shape.getPosition();
    Vector2f newPos;
    switch(e.key.code) {
        case Keyboard::Up:
            newPos = Vector2f(oldPos.x, oldPos.y - CHICKEN_MOVEMENT_AMOUNT);
            break;
        case Keyboard::Down:
            newPos = Vector2f(oldPos.x, oldPos.y + CHICKEN_MOVEMENT_AMOUNT);
            break;
        case Keyboard::Left:
            newPos = Vector2f(oldPos.x - CHICKEN_MOVEMENT_AMOUNT, oldPos.y);
            break;
        case Keyboard::Right:
            newPos = Vector2f(oldPos.x + CHICKEN_MOVEMENT_AMOUNT, oldPos.y);
            break;
    }
    if (!(newPos.x > WINDOW_WIDTH  - CHICKEN_SIZE_WIDTH || newPos.x < 0
          || newPos.y > WINDOW_HEIGHT - CHICKEN_SIZE_HEIGHT || newPos.y < 0)) {
        shape.setPosition(newPos);
    }
}
