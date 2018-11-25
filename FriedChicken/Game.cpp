#include "Game.hpp"

Game::Game() {
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken(r->getSize());
    human = new Human(r->getSize().x / 2, 0);
    human1 = new Human(r->getSize().x / 5, 0);
    human2 = new Human(r->getSize().x / 7, 0);
    human3 = new Human(r->getSize().x / 3, 0);
    human4 = new Human(r->getSize().x / 4, 0);
    human5 = new Human(r->getSize().x / 10, 0);
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
            human->Move(r->getSize());
            human1->Move(r->getSize());
            human2->Move(r->getSize());
            human3->Move(r->getSize());
            human4->Move(r->getSize());
            human5->Move(r->getSize());
        }
        if(chicken->GetShape().getGlobalBounds().intersects(human->GetShape().getGlobalBounds())){
            r->close();
        }
        r->clear();
        human->Draw(*r);
        human1->Draw(*r);
        human2->Draw(*r);
        human3->Draw(*r);
        human4->Draw(*r);
        human5->Draw(*r);
        
        chicken->Draw(*r);
        //insert here
        r->display();
    }
    
}
