#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include "ship.h"
#include "rocks.h"
#include "bullets.h"


class Game {
    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void close();

        bool running() { return !quit; }

    private:
        bool quit;
        SDL_Window* window;
};
#endif
