#ifndef ROCKS_H
#define ROCKS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Rock {
    public:
        Rock();
        ~Rock();
        void update();
        void render(SDL_Renderer* render);
        void free();
        const SDL_Rect& GetRect()const;

    private:
        SDL_Rect hitbox;
        int posX;
        int posY;
        int velX;
        int velY;
};

#endif
