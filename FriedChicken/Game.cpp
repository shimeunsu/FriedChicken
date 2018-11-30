#include "Game.hpp"
#include <sstream>
#define fontfile "Hack-Regular.ttf"
#include <random>
#include <fstream>

using namespace sf;
using namespace std;

/*!
 \brief "Constructor that creates the game with the window and sprites"
 */
Game::Game() {
    gameClock = new Clock();
    score = MAX_SCORE;
    rWindow = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    chicken = new Chicken();
    initHumans();
    srand(time(0));
}

/*!
 \brief "Create all the humans"
 */
void Game::initHumans() {
    for (int i = 0; i < (WINDOW_WIDTH / (HUMAN_SIZE_WIDTH * 5)) + 1; ++i) {
        Human* human = new Human((i+1)*100,0);
        humans.push_back(human);
        human->GetShape()->setPosition((i+1)*100, WINDOW_HEIGHT/2);
        if (i % 2 == 0) {
            Human* human2 = new Human((i+1)*100, WINDOW_HEIGHT/2);
                humans.push_back(human2);
                human2->GetShape()->setPosition((i+1)*100,0);
        }
    }
}

/*!
 \brief "Loop to run the game, listen to events, and run the score"
 \param "none"
 */
void Game::Loop() {
    while (rWindow->isOpen()) {
        Event e;
        if (gameClock->getElapsedTime() > seconds(.1)) {
            score--;
            updateTitle(rWindow, score);
            if(score == 0){
                rWindow->close();
            }
            gameClock->restart();
            
            //! Event listening
            while (rWindow->pollEvent(e)) {
                switch(e.type) {
                    case Event::EventType::Closed:
                        rWindow->close();
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
                    human->MoveDown(rWindow->getSize(),HUMAN_MOVEMENT_SPEED/2);
                } else {
                    human->MoveUp(rWindow->getSize(),HUMAN_MOVEMENT_SPEED);
                }
                i++;
            }
        }
        
        //! Victory detection
        if (chicken->GetShape()->getPosition().x > WINDOW_WIDTH - 2*CHICKEN_SIZE_WIDTH){
            gameWin(rWindow,score);
        }
        
        //! Human Chicken collision detection
        for (Human* human: humans) {
            if(chicken->GetShape()->getGlobalBounds().intersects(human->GetShape()->getGlobalBounds())){
                gameOver(rWindow);
                    }
        }

        
        //! Set the background colour
        rWindow->clear(BG_WINDOW);

        
        //! Draw the humans
        for (Human* human: humans){
          rWindow->draw(*human->GetShape());
        }

        //! Draw the chickens
        rWindow->draw(*chicken->GetShape());

        rWindow->display();
    }
}

/*!
 \brief "Set the title of window"
 \param "Pointer to the window and the score to print"
 */
void Game::updateTitle(Window* window, int score) {
    stringstream ss;
    ss << WINDOW_TITLE << ": " << score;
    window->setTitle(ss.str());
}

/*!
 \brief "Reset the game when playing again"
 */
void Game::reset() {
    chicken->GetShape()->setPosition(0, WINDOW_HEIGHT / 2);
    score = MAX_SCORE;
}

/*!
 \brief "Load the game over screen"
 \param "Pointer to the window"
 */
void Game::gameOver(RenderWindow* rWindow) {
    rWindow->clear(BG_WINDOW);
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
    Texture* texture = new Texture();
    texture->loadFromFile("sprite/chicken.png");
    shape = new Sprite(*texture);
    shape->setPosition(0,WINDOW_HEIGHT / 2);
    rWindow->draw(gameOverMsg);
    rWindow->display();
    while(rWindow->isOpen()) {
        Event e;
        while(rWindow->pollEvent(e)) {
            if (e.key.code == Keyboard::Q) {
                rWindow->close();
            }
            else if (e.key.code == Keyboard::R) {
                reset();
                Loop();
            }
        }
    }
    rWindow->close();
    exit(0);
}

/*!
 \brief "Load the victory screen"
 \param "Pointer to the window and the score to print"
 */
void Game::gameWin(RenderWindow* rWindow, int score) {
    rWindow->clear(BG_WINDOW);
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
    rWindow->draw(gameOverMsg);
    rWindow->display();
    while(rWindow->isOpen()) {
        Event e;
        while(rWindow->pollEvent(e)) {
            if (e.key.code == Keyboard::Q) {
                rWindow->close();
            }
            else if (e.key.code == Keyboard::R) {
                reset();
                Loop();
            }
        }
    }
    rWindow->close();
    exit(0);
}
