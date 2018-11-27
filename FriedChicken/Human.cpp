#include "Human.hpp"

using namespace sf;

Human::Human(float posX, float posY) {
    originalPosX = posX;
    originalPosY = posY;
    Texture* texture = new Texture();
    texture->loadFromFile("sprite/human.png");
    shape = new Sprite(*texture);
}

void Human::MoveDown(Vector2u size) {
    shape->move(0.0, HUMAN_MOVEMENT_SPEED);
    if (shape->getPosition().x > size.x){
        shape->setPosition(Vector2f(-shape->getTexture()->getSize().x, originalPosY));
    }

    if (shape->getPosition().y >= WINDOW_HEIGHT - HUMAN_SIZE_HEIGHT){
        shape->setPosition(Vector2f(shape->getPosition().x, 0));
    }

    if (shape->getPosition().y < 0){
        shape->setPosition(Vector2f(shape->getPosition().x, WINDOW_HEIGHT));
    }
}

void Human::MoveUp(Vector2u size){
    shape->move(0.0, -HUMAN_MOVEMENT_SPEED);
    if (shape->getPosition().x > size.x){
        shape->setPosition(Vector2f(-shape->getTexture()->getSize().x, originalPosY));
    }

    if (shape->getPosition().y >= WINDOW_HEIGHT + HUMAN_SIZE_HEIGHT){
        shape->setPosition(Vector2f(shape->getPosition().x, 0));
    }

    if (shape->getPosition().y < 0){
        shape->setPosition(Vector2f(shape->getPosition().x, WINDOW_HEIGHT));
    }

}



