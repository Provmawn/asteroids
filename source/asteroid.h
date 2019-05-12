#ifndef ASTEROID_H
#define ASTEROID_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Asteroid {
    public:
        Asteroid();
        ~Asteroid();
        void update();
        void render(SDL_Renderer* render, SDL_Texture* sprite, int x, int y);
        void free();
        const SDL_Rect& getRect() const;

    private:
        SDL_Rect hitbox;
        int posX;
        int posY;
        int velX;
        int velY;
};

#endif
