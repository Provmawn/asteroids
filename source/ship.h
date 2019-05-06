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
        const SDL_Rect& getRect() const;

        void free();
        void lowerHp();

        void bulletUpdate(int i);
        void bulletRender(int i, SDL_Renderer* renderer);
        void removeBullet(int i);

        const SDL_Rect& getBulletHitbox(int i) const { return bulletList[i].getRect(); }
        int getBulletListSize() { return bulletList.size(); }
        bool bulletIsRemovable(int i) { return bulletList[i].isRemovable(); }
        void setBulletRemoveStatus(int i, bool status) { bulletList[i].setRemoveStatus(status); }
    private:
        void calculateBulletVelocity();
        std::vector<Bullet> bulletList;
        SDL_Rect hitbox;
        int mouseX;
        int mouseY;
        double bulletAccelX, bulletAccelY;
        double posX ,posY;
        double velX, velY;
        double accelX, accelY;
        int hp;
        unsigned int atkSpd;
        bool up, left, down, right, shooting;
};

#endif
