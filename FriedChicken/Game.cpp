#include "Game.hpp"
#include <sstream>
#define fontfile "Hack-Regular.ttf"

using namespace sf;
using namespace std;

/*!
 \brief "Constructor that creates the game with the window and sprites"
 \param "none"
 */
Game::Game() {
    gameClock = new Clock();
    score = MAX_SCORE;
    r = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken();
    initHumans();
}

/*!
 \brief "Create all the humans"
 \param "none"
 */
void Game::initHumans() {
    for (int i = 0; i < (WINDOW_WIDTH / (HUMAN_SIZE_WIDTH * 5)) + 1; ++i) {
        Human* human = new Human((i+1)*100,0);
        humans.push_back(human);
        human->GetShape()->setPosition((i+1)*100,0);
    }
}

/*!
 \brief "Loop to run the game, listen to events, and run the score"
 \param "none"
 */
void Game::Loop() {
    while (r->isOpen()) {
        Event e;
        if (gameClock->getElapsedTime() > seconds(.1)) {
            score--;
            updateTitle(r, score);
            if(score == 0){
                r->close();
            }
            gameClock->restart();
            
            //! Event listening
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

            //! Move the humans
            int i = 0;
            for (Human* human: humans) {
                if (i % 2 == 0) {
                    human->MoveDown(r->getSize(),HUMAN_MOVEMENT_SPEED);
                } else {
                    human->MoveUp(r->getSize());
                }
                i++;
            }
        }
        
        //! Victory detection
        if (chicken->GetShape()->getPosition().x > WINDOW_WIDTH - 2*CHICKEN_SIZE_WIDTH){
            gameWin(r,score);
        }
        
        //! Human Chicken collision detection
        for (Human* human: humans) {
            if(chicken->GetShape()->getGlobalBounds().intersects(human->GetShape()->getGlobalBounds())){
                gameOver(r);
                    }
        }

        
        //! Set the background colour
        r->clear(BG_WINDOW);

        
        //! Draw the humans
        for (Human* human: humans){
          r->draw(*human->GetShape());
        }

        //! Draw the chickens
        r->draw(*chicken->GetShape());

        r->display();
    }
}

/*!
 \brief "Set the title of window"
 \param "Pointer to the window and the score to print"
 */
void Game::updateTitle(Window* w, int score) {
    stringstream ss;
    ss << WINDOW_TITLE << ": " << score;
    w->setTitle(ss.str());
}

/*!
 \brief "Reset the game when playing again"
 \param "none"
 */
void Game::reset() {
    chicken->GetShape()->setPosition(0, WINDOW_HEIGHT / 2);
    score = MAX_SCORE;
}

/*!
 \brief "Load the game over screen"
 \param "Pointer to the window"
 */
void Game::gameOver(RenderWindow* r) {
    r->clear(BG_WINDOW);
    Text gameOverMsg;
    Font f;
    f.loadFromFile(fontfile);
    gameOverMsg.setFont(f);
    stringstream msgText;
    msgText << "Game Over!" << endl << "Press Q to quit" << endl << "Press R to retry" << endl;
    gameOverMsg.setString(msgText.str());
    gameOverMsg.setCharacterSize(20);
    gameOverMsg.setFillColor(Color::White);
    gameOverMsg.setPosition(10,10);
    r->draw(gameOverMsg);
    r->display();
    while(r->isOpen()) {
        Event e;
        while(r->pollEvent(e)) {
            if (e.key.code == Keyboard::Q) {
                r->close();
            }
            else if (e.key.code == Keyboard::R) {
                reset();
                Loop();
            }
        }
    }
    r->close();
    exit(0);
}

/*!
 \brief "Load the victory screen"
 \param "Pointer to the window and the score to print"
 */
void Game::gameWin(RenderWindow* r, int score) {
    r->clear(BG_WINDOW);
    Text gameOverMsg;
    Font f;
    f.loadFromFile(fontfile);
    gameOverMsg.setFont(f);
    stringstream msgText;
    msgText << "You WON!" << endl << "Score: " << score << endl << "Press Q to quit" << endl << "Press R to retry" << endl;
    gameOverMsg.setString(msgText.str());
    gameOverMsg.setCharacterSize(20);
    gameOverMsg.setFillColor(Color::White);
    gameOverMsg.setPosition(10,10);
    r->draw(gameOverMsg);
    r->display();
    while(r->isOpen()) {
        Event e;
        while(r->pollEvent(e)) {
            if (e.key.code == Keyboard::Q) {
                r->close();
            }
            else if (e.key.code == Keyboard::R) {
                reset();
                Loop();
            }
        }
    }
    r->close();
    exit(0);
}
