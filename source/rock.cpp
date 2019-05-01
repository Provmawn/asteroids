#include "rock.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;



Rock::Rock() {
    hitbox.x=0;
    hitbox.y=0;
    hitbox.w=10;
    hitbox.h=10;
    posX = ::SCREEN_WIDTH / 2;
    posY = ::SCREEN_HEIGHT / 2;
    std::cout << __FILE__ << ": constructor..." << std::endl;
    velX = (rand() % 10) + 1;
    velY = (rand() % 10) + 1;
}

Rock::~Rock() {
}

void Rock::update() {
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

void Rock::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}


void Rock::free() {
    delete this;
}

const SDL_Rect& Rock::GetRect()const{

return hitbox;


}
