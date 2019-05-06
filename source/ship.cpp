#include "ship.h"

Ship::Ship() 
    : mouseX(0), mouseY(0), bulletVelX(0), bulletVelY(0), posX(0), posY(0), velX(5), velY(5), hp(3), atkSpd(0)
{
    hitbox.x = 0;
    hitbox.y = 0;
    hitbox.w = 100;
    hitbox.h = 100;
}

Ship::~Ship() {
}

void Ship::update() {
    hitbox.x = posX;
    hitbox.y = posY;
    ++atkSpd;
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
    if ( currentKeyStates[ SDL_SCANCODE_SPACE ] && atkSpd % 5 == 0 ) {
        SDL_GetMouseState(&mouseX, &mouseY);
        calculateBulletVelocity();
        bulletList.push_back(Bullet(posX + hitbox.w / 2, posY + hitbox.h / 2, bulletVelX, bulletVelY));
    }
}

void Ship::lowerHp() {
    --hp;
}

void Ship::free() {
    velX = 0;
    velY = 0;
}

void Ship::calculateBulletVelocity() {
    double dx = mouseX - (posX + hitbox.w / 2);
    double dy = mouseY - (posY + hitbox.h / 2);;
    double theta = atan2(dy, dx);
    bulletVelX = cos(theta) * 5.0;
    bulletVelY = sin(theta) * 5.0;
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

const SDL_Rect& Ship::getRect() const {
    return hitbox;
}
