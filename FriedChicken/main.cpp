#include <iostream>
#include <SFML/Graphics.hpp>
#include "Chicken.hpp"

using namespace std;
using namespace sf;

int main() {
    // insert code here...
    RenderWindow* r = new RenderWindow(VideoMode(640, 480), "test");
    Chicken chicken(r->getSize());
    
    
    RectangleShape human;
    human.setSize(Vector2f(60,120));
    human.setFillColor(Color::Yellow);
    human.setPosition(Vector2f(human.getPosition().x, r->getSize().y / 2 - human.getSize().y));
    
    while (r->isOpen()) {
        Event e;
        
        while (r->pollEvent(e)) {
            
            if(Event::KeyReleased){
                
                chicken.Move(e);
            
        }
      
            //if (e.type == Event::Closed) r->close();

            
        }
        //update the game
        human.move(0.2, 0.0);
        if(human.getPosition().x > r->Window::getSize().x){
            human.setPosition(Vector2f(-human.getSize().x, r->getSize().y / 2 - human.getSize().y));
        }
         
        if(chicken.GetShape().getGlobalBounds().intersects(human.getGlobalBounds()){
            r->close();
        }
        r->clear();
        
        r->draw(human);
           chicken.Draw(r);
        //insert here
        r->display();
    }
    std::cout << "Hello, World!\n";
    return 0;
}
