#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include "bullet.h"

class Player {
    public:
        Player();
        ~Player();
        void update();
        void render(SDL_Renderer* render, SDL_Texture* sprite, int x, int y);
        void handleEvents(SDL_Event e);
        const SDL_Rect& getRect() const;

        void free();
        void lowerHp();

        bool isMoving() { return up || left || down || right; }

        void removeBullet(int i);
        std::vector<Bullet>& getBullets() { return bulletList; }

        double getPosX() const { return posX; }
        double getPosY() const { return posY; }
        double getWidth() const { return hitbox.w; }
        double getHeight() const { return hitbox.h; }

    private:
        void calculateBulletVelocity();
        std::vector<Bullet> bulletList;
        SDL_Rect hitbox;
        int mouseX;
        int mouseY;
        double bulletX, bulletY;
        double bulletAccelX, bulletAccelY;
        double posX ,posY;
        double velX, velY;
        double theta, dx, dy;
        double accelX, accelY;
        int hp;
        unsigned int atkSpd;
        bool up, left, down, right, shooting;
};

#endif
