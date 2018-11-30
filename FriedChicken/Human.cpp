#include "Human.hpp"

using namespace sf;

/*!
 \brief "Constructor that creates the human"
 \param "X and Y coordinates of the position"
 \return "Human object"
 */
Human::Human(float posX, float posY) {
    originalPosX = posX;
    originalPosY = posY;
    Texture* texture = new Texture();
    
    if (rand() % 2 == 0) {
      texture->loadFromFile("sprite/human.png");
    }
    else{
        texture->loadFromFile("sprite/human2.png");
    }
    shape = new Sprite(*texture);
}

/*!
 \brief "Move the human down"
 \param "The size of the window and takes speed"
 */
void Human::MoveDown(Vector2u size, float speed) {
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

/*!
 \brief "Move the human up"
 \param "The size of the window and takes speed"
 */
void Human::MoveUp(Vector2u size, float speed){
    shape->move(0.0, -speed);
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
