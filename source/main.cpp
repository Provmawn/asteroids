#include "game.h"
#include <cstdlib>
#include <ctime>

Game game;

extern const int SCREEN_WIDTH = 1080;
extern const int SCREEN_HEIGHT = 720;

int main(int argc, const char* argv[]) {
    srand(time(nullptr));
    game.init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    if (!game.loadMedia()) {
        std::cerr << "Unable to load media!" << std::endl;
        return 1;
    }
    while (game.running()) {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.close();
    return 0;
}
