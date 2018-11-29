#include "Game.hpp"

using namespace std;
using namespace sf;

/*!
 \brief "Main function that creates and exectutes the game loop"
 */
int main() {
    Game* game = new Game();
    game->Loop();
    return EXIT_SUCCESS;
}
