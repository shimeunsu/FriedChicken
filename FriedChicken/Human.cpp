#include "Human.hpp"

using namespace sf;

/*!
 \brief "Constructor that creates the human"
 \param "X and Y coordinates of the position"
 */
Human::Human(float posX, float posY) {
    originalPosX = posX;
    originalPosY = posY;
    Texture* texture = new Texture();
    texture->loadFromFile("sprite/human.png");
    shape = new Sprite(*texture);
}

/*!
 \brief "Move the human down"
 \param "The size of the window"
 */
void Human::Move(Vector2u size, float speed) {
    shape->move(0.0, speed);
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


