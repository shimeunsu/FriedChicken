#include "Game.hpp"

using namespace std;
using namespace sf;

int main() {
    Game* game = new Game();
    game->Loop();
    return EXIT_SUCCESS;
}
