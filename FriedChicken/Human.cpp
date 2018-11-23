#include "Human.hpp"

Human::Human(float posX, float posY){
    Texture texture =Texture();
    texture.loadFromFile("sprite/human.png");
    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(posX,posY));
    originalPosX = posX;
    originalPosY = posY;

}

void Human::Move(Vector2u size) {
    sprite.move(0, HUMAN_MOVEMENT_SPEED);
    if (sprite.getPosition().x > size.x) {
        sprite.setPosition(Vector2f(-HUMAN_SIZE_WIDTH, originalPosY));
    }

    if (sprite.getPosition().y >= WINDOW_HEIGHT - HUMAN_SIZE_HEIGHT) {
        sprite.setPosition(Vector2f(sprite.getPosition().x, 0));
    }

    if (sprite.getPosition().y < 0) {
        sprite.setPosition(Vector2f(sprite.getPosition().x, WINDOW_HEIGHT));
    }

}




