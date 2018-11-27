#include "Game.hpp"

using namespace sf;

Game::Game() {
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken(r->getSize());
    initHumans();
}
void Game::initHumans(){
   Texture* human1 = new Texture();
   if(!human1->loadFromFile("sprite/human.png"))
       std::cout << "Failed to load human Sprite" << std::endl;
  Human* human = new Human(r->getSize().x / 2, 0);
   human->GetShape()->setTexture(*human1);
   human->Draw(r);

    for (int i = 0; i < 30 ; ++i) {
        humans.push_back(new Human((i+1)*100,0));
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
            int i = 0;
            for (Human* human: humans){
                if (i % 2 == 0) {
                    human->MoveDown(r->getSize());
                } else {
                    humans[i]->MoveUp(r->getSize());
                }
                i++;
            }
        }

//        if(chicken->GetShape().getGlobalBounds().intersects(human->GetShape().getGlobalBounds())){
//            r->close();
//        }

        for (Human* human: humans) {

            if(chicken->GetShape()->getGlobalBounds().intersects(human->GetShape()->getGlobalBounds())){
                        r->close();
                    }

        }

        r->clear();

        for (Human* human: humans){
          human->Draw(r);
        }

        chicken->Draw(r);
        //insert here
        r->display();
    }

}


