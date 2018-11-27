#include "Game.hpp"

using namespace sf;
using namespace std;

Game::Game() {
    gameClock = new Clock();
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken();
    initHumans();
}
void Game::initHumans() {
    for (int i = 0; i < 30 ; ++i) {
        Human* human = new Human((i+1)*100,0);
        humans.push_back(human);
        human->GetShape()->setPosition((i+1)*100,0);
    }
}
void Game::Loop() {
    while (r->isOpen()) {
        Event e;
        if (gameClock->getElapsedTime() > seconds(.1)) {
            gameClock->restart();
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


            //update the game
            int i = 0;
            for (Human* human: humans) {
                if (i % 2 == 0) {
                    human->MoveDown(r->getSize());
                } else {
                    human->MoveUp(r->getSize());
                }
                i++;
            }
        }

        for (Human* human: humans) {

            if(chicken->GetShape()->getGlobalBounds().intersects(human->GetShape()->getGlobalBounds())){
                        r->close();
                    }

        }

        r->clear();

        for (Human* human: humans){
          r->draw(*human->GetShape());
        }

        r->draw(*chicken->GetShape());
        //insert here

        r->display();

    }

}