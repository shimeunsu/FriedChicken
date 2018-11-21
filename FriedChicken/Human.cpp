#include "Human.hpp"

Human::Human(float posX, float posY){
    human.setSize(Vector2f(60,120));
    human.setFillColor(Color::Yellow);
    human.setPosition(Vector2f(posX,posY));
    
    originalPosX = posX;
    originalPosY = posY;
    
}
void Human::Draw(RenderWindow &r){
    r.draw(human);
}
void Human::Move(Vector2u size){
    human.move(0.2, 0.0);
    if(human.getPosition().x > size.x){
        human.setPosition(Vector2f(-human.getSize().x, originalPosY));
    }
    
    
}
RectangleShape Human::GetShape(){
    return human;
    
}



