#include "Game.hpp"

Game::Game() {
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken(r->getSize());
    human = new Human(r->getSize().x / 2, 0);

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
        }
            if(chicken->getSprite().getGlobalBounds().intersects(human->getSprite().getGlobalBounds())){
                r->close();
            }
            r->clear();
            human->draw(r);
            chicken->draw(r);
            //insert here
            r->display();
    }

}
