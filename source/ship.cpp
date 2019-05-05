#include "ship.h"

Ship::Ship() 
    : bulletVelX(0), bulletVelY(0), posX(0), posY(0), velX(2), velY(2)
{
    hitbox.x = 0;
    hitbox.y = 0;
    hitbox.w = 100;
    hitbox.h = 100;
}

Ship::~Ship() {
    free();
}

void Ship::update() {
    hitbox.x = posX;
    hitbox.y = posY;
}

void Ship::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}

void Ship::handleEvents(SDL_Event e) {
    static const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if ( currentKeyStates[ SDL_SCANCODE_W ] ) {
        posY -= velY; 
    }
    if ( currentKeyStates[ SDL_SCANCODE_A ] ) {
        posX -= velX;
    }
    if ( currentKeyStates[ SDL_SCANCODE_S ] ) {
        posY += velY;
    }
    if ( currentKeyStates[ SDL_SCANCODE_D ] ) {
        posX += velX; 
    }
    if ( currentKeyStates[ SDL_SCANCODE_SPACE ] ) {
        SDL_GetMouseState(&mouseX, &mouseY);
        calculateBulletVelocity();
        bulletList.push_back(Bullet(posX + hitbox.w / 2, posY + hitbox.h / 2, bulletVelX, bulletVelY));
    }
}

void Ship::calculateBulletVelocity() {
    double dx = mouseX - posX;
    double dy = mouseY - posY;
    double theta = atan2(dy, dx);
    bulletVelX = cos(theta) * 5.0;
    bulletVelY = sin(theta) * 5.0;
}

void Ship::free() {
    velX = 0;
    velY = 0;
}

void Ship::removeBullet(int i) {
    std::swap(bulletList[i], bulletList.back());
    bulletList.pop_back();
}

void Ship::bulletUpdate(int i) {
    bulletList[i].update();
}

void Ship::bulletRender(int i, SDL_Renderer* renderer) {
    bulletList[i].render(renderer);
}
