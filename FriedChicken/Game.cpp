

#include "Game.hpp"

Game::Game(){
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken(r->getSize());
    human = new Human(0,r->getSize().y / 2);
    
}

void Game::Loop(){
    while (r->isOpen()) {
        Event e;
        
        while (r->pollEvent(e)) {
            
            if(Event::KeyReleased){
                
                chicken->Move(e);
                
            }
            
            //if (e.type == Event::Closed) r->close();
 
        }
        //update the game
        human->Move(r->getSize());
        
        if(chicken->GetShape().getGlobalBounds().intersects(human->GetShape().getGlobalBounds())){
            r->close();
        }
        r->clear();
        human->Draw(*r);
        chicken->Draw(*r);
        //insert here
        r->display();
    }
    
}
