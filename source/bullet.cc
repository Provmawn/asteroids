#include "bullet.h"

extern const int LEVEL_WIDTH;
extern const int LEVEL_HEIGHT;


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
    if (posX < 0 || posX + hitbox.w > ::LEVEL_WIDTH ||
       posY < 0 || posY + hitbox.h > ::LEVEL_HEIGHT) {
        removeStatus = true;
    }
}

void Bullet::render(SDL_Renderer* render, SDL_Texture* sprite, int x, int y) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect renderQuad = {static_cast<int>(posX) - x, static_cast<int>(posY) - y, hitbox.w, hitbox.h};
    SDL_RenderCopyEx(render, sprite, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}

void Bullet::free() {
}
