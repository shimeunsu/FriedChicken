#include "Human.hpp"

Human::Human(float posX, float posY){
    shape.setSize(Vector2f(HUMAN_SIZE_WIDTH,HUMAN_SIZE_HEIGHT));
    shape.setFillColor(Color::Yellow);
    shape.setPosition(Vector2f(posX,posY));
    
    originalPosX = posX;
    originalPosY = posY;
    
}

void Human::MoveDown(Vector2u size){
    shape.move(0.0, HUMAN_MOVEMENT_SPEED);
    if (shape.getPosition().x > size.x){
        shape.setPosition(Vector2f(-shape.getSize().x, originalPosY));
    }
    
    if (shape.getPosition().y >= WINDOW_HEIGHT - HUMAN_SIZE_HEIGHT){
        shape.setPosition(Vector2f(shape.getPosition().x, 0));
    }
    
    if (shape.getPosition().y < 0){
        shape.setPosition(Vector2f(shape.getPosition().x, WINDOW_HEIGHT));
    }
    
}

void Human::MoveUp(Vector2u size){
    shape.move(0.0, -HUMAN_MOVEMENT_SPEED);
    if (shape.getPosition().x > size.x){
        shape.setPosition(Vector2f(-shape.getSize().x, originalPosY));
    }
    
    if (shape.getPosition().y >= WINDOW_HEIGHT - HUMAN_SIZE_HEIGHT){
        shape.setPosition(Vector2f(shape.getPosition().x, 0));
    }
    
    if (shape.getPosition().y < 0){
        shape.setPosition(Vector2f(shape.getPosition().x, WINDOW_HEIGHT));
    }
    
}



