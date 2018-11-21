#include <iostream>
#include <SFML/Graphics.hpp>
#include "Chicken.hpp"
using namespace sf;

Chicken::Chicken(Vector2u size){
    chicken.setSize(Vector2f(80.0f,80.0f));
    chicken.setPosition(Vector2f(chicken.getPosition().x, size.y - chicken.getSize().y));
}
void Chicken::Draw(RenderWindow &r){
    r.draw(chicken); 
}
void Chicken::Move(Event e){
    if(Keyboard::Key::Right == e.key.code){
        chicken.move(80,0);
    }
    else if(Keyboard::Key::Left == e.key.code){
        chicken.move(-80,0);
    }
    else if(Keyboard::Key::Up == e.key.code){
        chicken.move(0,-80);
    }
    else if(Keyboard::Key::Down == e.key.code){
        chicken.move(0,80);
    }
}

RectangleShape Chicken::GetShape(){
    return chicken;
    
}
