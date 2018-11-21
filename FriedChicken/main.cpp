#include <iostream>
#include <SFML/Graphics.hpp>
#include "Chicken.hpp"
#include "Chicken.cpp"
#include "Game.hpp"
#include "Game.cpp"
#include "Human.hpp"
#include "Human.cpp"

using namespace std;
using namespace sf;

int main() {
    
    Game game;
    game.Loop();
    return EXIT_SUCCESS;
    

  
}
