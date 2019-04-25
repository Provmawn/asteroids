#ifndef SHIP_H
#define SHIP_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Ship {
    public:
        Ship();
        ~Ship();
        void update();
        void render(SDL_Renderer* render);
        void handleEvents(SDL_Event e);
        void free();
    private:
        SDL_Rect hitbox;
        int posX;
        int posY;
        int velX;
        int velY;
};

#endif
