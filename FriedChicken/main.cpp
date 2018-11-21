#include <iostream>
#include <SFML/Graphics.hpp>
#include "Chicken.hpp"
#include "Chicken.cpp"
#include "Human.hpp"
#include "Human.cpp"

using namespace std;
using namespace sf;

int main() {
    // insert code here...
    RenderWindow r(VideoMode(640, 480), "test");
    Chicken chicken(r.getSize());
    Human human(0,r.getSize().y / 2);
    
    while (r.isOpen()) {
        Event e;
        
        while (r.pollEvent(e)) {
            
            if(Event::KeyReleased){
                
                chicken.Move(e);
            
        }
      
            //if (e.type == Event::Closed) r->close();

            
        }
        //update the game
        human.Move(r.getSize());
        
        if(chicken.GetShape().getGlobalBounds().intersects(human.GetShape().getGlobalBounds())){
            r.close();
        }
        r.clear();
        human.Draw(r);
        chicken.Draw(r);
        //insert here
        r.display();
    }
  
}
