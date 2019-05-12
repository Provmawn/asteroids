#ifndef BULLET_H
#define BULLET_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Bullet {
    public:
        Bullet(double x = 0.0, double y = 0.0, double ax = 0.0, double ay = 0.0);
        ~Bullet();
        void update();
        void render(SDL_Renderer* render, SDL_Texture* sprite, int x, int y);
        void free();
        const SDL_Rect& getRect() const;

        void setRemoveStatus(bool status) { removeStatus = status; }
        bool isRemovable() { return removeStatus; }

        const SDL_Rect& getHitbox() const { return hitbox; }
    private:
        SDL_Rect hitbox;
        double posX, posY;
        double velX, velY;
        double accelX, accelY;

        bool removeStatus;
};

#endif
