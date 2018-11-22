

#include "Game.hpp"

Game::Game(){
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken(r->getSize());
    human = new Human(r->getSize().x / 2, 0);

}

void Game::Loop(){
    while (r->isOpen()) {
        Event e;

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
