#include "bullet.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


Bullet::Bullet(double x, double y, double ax, double ay)
    : posX(x), posY(y), velX(0.0), velY(0.0), accelX(ax), accelY(ay), removeStatus(false)
{
    hitbox.x = 0;
    hitbox.y = 0;
    hitbox.w = 1;
    hitbox.h = 1;
}

Bullet::~Bullet() {
}

void Bullet::update() {
    velX += accelX;
    velY += accelY;
    posX += velX;
    posY += velY;
    hitbox.x = posX;
    hitbox.y = posY;
    if (posX < 0 || posX + hitbox.w > ::SCREEN_WIDTH ||
       posY < 0 || posY + hitbox.h > ::SCREEN_HEIGHT) {
        removeStatus = true;
    }
}

void Bullet::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}

void Bullet::free() {
}

const SDL_Rect& Bullet::getRect() const {
    return hitbox;
}

