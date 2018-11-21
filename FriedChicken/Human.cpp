#include "Human.hpp"

Human::Human(float posX, float posY){
    shape.setSize(Vector2f(HUMAN_SIZE_WIDTH,HUMAN_SIZE_HEIGHT));
    shape.setFillColor(Color::Yellow);
    shape.setPosition(Vector2f(posX,posY));
    
    originalPosX = posX;
    originalPosY = posY;
    
}

void Human::Move(Vector2u size){
    shape.move(HUMAN_MOVEMENT_SPEED, 0.0);
    if (shape.getPosition().x > size.x){
        shape.setPosition(Vector2f(-shape.getSize().x, originalPosY));
    }
    
    
}




