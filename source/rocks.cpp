#include "rocks.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


Rocks::Rocks() {
    hitbox.x=0;
    hitbox.y=0;
    hitbox.w=10;
    hitbox.h=10;
    posX = 0;
    posY = 0;
    velX = 1;
    velY = 1;
}

Rocks::~Rocks() {
    free();
}

void Rocks::update() {
    hitbox.x = posX;
    hitbox.y = posY;
    posX += velX;
    posY += velY;
    if (posX < 0 || posX + hitbox.w > ::SCREEN_WIDTH) {
        velX = -velX;
    }
    if (posY < 0 || posY + hitbox.h > ::SCREEN_HEIGHT) {
        velY = -velY;
    }
}

void Rocks::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}


void Rocks::free() {
    velX = 0;
    velY = 0;
}

const SDL_Rect& Rocks::GetRect()const{

return hitbox;


}
