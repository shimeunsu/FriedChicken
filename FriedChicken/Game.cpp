#include "Game.hpp"

Game::Game() {
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken(r->getSize());
    initHumans();
}
void Game::initHumans(){
//    Texture human1;
//    if(!human1.loadFromFile("sprite/human.png"))
//        std::cout << "Failed to load human Sprite" << std::endl;
//   human = new Human(r->getSize().x / 2, 0);
//    human->setTexture(human1);
//    r->Draw(human);
    
    for (int i =0; i <30 ; ++i){
        humans[i] = new Human( (i+1)*100,0 );
    }
    
    
}
void Game::Loop(){
    Clock* clock = new Clock();
    while (r->isOpen()) {
        Event e;
        if (clock->getElapsedTime() > seconds(.1)) {
            clock->restart();
            while (r->pollEvent(e)) {
                switch(e.type) {
                    case Event::EventType::Closed:
                        r->close();
                        break;
                    case Event::EventType::KeyPressed:
                        if (e.key.code == Keyboard::Up ||
                            e.key.code == Keyboard::Down ||
                            e.key.code == Keyboard::Left ||
                            e.key.code == Keyboard::Right)
                            chicken->Move(e);
                        break;
                }
            }
            //if (e.type == Event::Closed) r->close();
            
            
            //update the game
            for (int i =0; i <30 ; ++i){
                
                humans[i]->Move(r->getSize());
                
            }

        }
      
//        if(chicken->GetShape().getGlobalBounds().intersects(human->GetShape().getGlobalBounds())){
//            r->close();
//        }
        
        for (int i =0; i <30 ; ++i){
            
            if(chicken->GetShape().getGlobalBounds().intersects(humans[i]->GetShape().getGlobalBounds())){
                        r->close();
                    }
            
        }
        
        r->clear();
        
        for (int i =0; i <30 ; ++i){
            
          humans[i]->Draw(*r);
            
        }
        //humans[0]->Draw(*r);
            //human->Draw(*r);

//
        chicken->Draw(*r);
        //insert here
        r->display();
    }
    
}


