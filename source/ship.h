#ifndef SHIP_H
#define SHIP_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include "bullet.h"

class Ship {
    public:
        Ship();
        ~Ship();
        void update();
        void render(SDL_Renderer* render);
        void handleEvents(SDL_Event e);
        void free();
        void removeBullet(int i);
        void bulletUpdate(int i);
        void bulletRender(int i, SDL_Renderer* renderer);
        bool bulletIsRemovable(int i) { return bulletList[i].isRemovable(); }
        int getBulletListSize() { return bulletList.size(); }
    private:
        void calculateBulletVelocity();
        std::vector<Bullet> bulletList;
        SDL_Rect hitbox;
        int mouseX;
        int mouseY;
        double bulletVelX;
        double bulletVelY;
        int posX;
        int posY;
        int velX;
        int velY;
};

#endif
