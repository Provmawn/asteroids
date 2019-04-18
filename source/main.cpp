#include "game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) {
    game = new Game();

    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, false);
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->close();
    return 0;
}
