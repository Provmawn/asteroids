#include "asteroid.h"

extern const int LEVEL_WIDTH;
extern const int LEVEL_HEIGHT;

Asteroid::Asteroid() {
    hitbox.x=0;
    hitbox.y=0;
    hitbox.w=50;
    hitbox.h=50;
    posX = (rand() % ::LEVEL_WIDTH) + 1;
    posY = (rand() % ::LEVEL_HEIGHT) + 1;
    velX = 1;
    velY = 1;
    std::cout << __FILE__ << ": constructor..." << std::endl;
}

Asteroid::~Asteroid() {
}

void Asteroid::update() {
    hitbox.x = posX;
    hitbox.y = posY;
    posX += velX;
    posY += velY;
    if (posX < 0 || posX + hitbox.w > ::LEVEL_WIDTH) {
        velX = -velX;
    }
    if (posY < 0 || posY + hitbox.h > ::LEVEL_HEIGHT) {
        velY = -velY;
    }
}

void Asteroid::render(SDL_Renderer* render, SDL_Texture* sprite, int x, int y) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect renderQuad = {posX - x, posY - y, hitbox.w, hitbox.h};
    SDL_RenderCopyEx(render, sprite, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}


void Asteroid::free() {
    
}

const SDL_Rect& Asteroid::getRect() const{
    return hitbox;
}
