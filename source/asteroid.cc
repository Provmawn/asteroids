#include "asteroid.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

Asteroid::Asteroid() {
    hitbox.x=0;
    hitbox.y=0;
    hitbox.w=50;
    hitbox.h=50;
    posX = (rand() % ::SCREEN_WIDTH) + 1;
    posY = (rand() % ::SCREEN_HEIGHT) + 1;
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
    if (posX < 0 || posX + hitbox.w > ::SCREEN_WIDTH) {
        velX = -velX;
    }
    if (posY < 0 || posY + hitbox.h > ::SCREEN_HEIGHT) {
        velY = -velY;
    }
}

void Asteroid::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}


void Asteroid::free() {
    
}

const SDL_Rect& Asteroid::getRect() const{
    return hitbox;
}
