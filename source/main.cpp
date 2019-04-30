#include "game.h"

Game* game = nullptr;

extern const int SCREEN_WIDTH = 1080;
extern const int SCREEN_HEIGHT = 720;

int main(int argc, const char* argv[]) {
    game = new Game();

    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->close();
    return 0;
}
