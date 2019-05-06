#include "ship.h"

Ship::Ship() 
    : mouseX(0), mouseY(0), bulletVelX(0), bulletVelY(0), posX(0), posY(0), velX(5), velY(5), hp(3), atkSpd(0),
      up(false), left(false), down(false), right(false), shooting(false)
{
    hitbox.x = 0;
    hitbox.y = 0;
    hitbox.w = 32;
    hitbox.h = 32;
}

Ship::~Ship() {
}

void Ship::update() {
    if (up) { posY -= velY; }
    if (left) { posX -= velX; }
    if (down) { posY += velY; }
    if (right) { posX += velX; }
    hitbox.x = posX;
    hitbox.y = posY;
    if (++atkSpd % 10 == 0 && shooting) {
        SDL_GetMouseState(&mouseX, &mouseY);
        calculateBulletVelocity();
        bulletList.push_back(Bullet(posX + hitbox.w / 2, posY + hitbox.h / 2, bulletVelX, bulletVelY));
    }
}

void Ship::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}

void Ship::handleEvents(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
        std::cout << "KEYDOWN" << std::endl;
        switch (e.key.keysym.sym) {
            case SDLK_w:
                up = true;
                break;
            case SDLK_a:
                left = true;
                break;
            case SDLK_s:
                down = true;
                break;
            case SDLK_d:
                right = true;
                break;
            case SDLK_SPACE:
                shooting = true;
                break;
            default:
                break;
        }
    }
    if (e.type == SDL_KEYUP) {
        switch (e.key.keysym.sym) {
            case SDLK_w:
                up = false;
                break;
            case SDLK_a:
                left = false;
                break;
            case SDLK_s:
                down = false;
                break;
            case SDLK_d:
                right = false;
                break;
            case SDLK_SPACE:
                shooting = false;
                break;
            default:
                break;
        }
    }
/*
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
    }*/
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
