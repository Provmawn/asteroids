#ifndef ROCK_H
#define ROCK_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Rock {
    public:
        Rock();
        ~Rock();
        void update();
        void subpixel();
        void render(SDL_Renderer* render);
        void free();
        const SDL_Rect& getRect() const;

    private:
        SDL_Rect hitbox;
        int posX;
        int posY;
        int velX;
        int velY;
        int subX;
        int subY;
};

#endif
