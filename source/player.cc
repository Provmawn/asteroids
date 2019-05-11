#include "player.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

Player::Player() 
    : mouseX(0), mouseY(0), bulletAccelX(0.0), bulletAccelY(0.0), posX(0.0), posY(0.0), velX(0.0), velY(0.0), 
      theta(0.0), accelX(.5), accelY(.5), hp(3), atkSpd(0), up(false), left(false), down(false), right(false), 
      shooting(false)
{
    hitbox.x = 0;
    hitbox.y = 0;
    hitbox.w = 32;
    hitbox.h = 32;
}

Player::~Player() {
}

void Player::update() {
    // movement
    if (up) { velY -= accelY; }
    if (left) { velX -= accelX; }
    if (down) { velY += accelY; }
    if (right) { velX += accelX; }
    posX += velX;
    posY += velY;

    // out of bounds checking
    if (posX + hitbox.w > ::SCREEN_WIDTH) {
        posX = ::SCREEN_WIDTH - hitbox.w;
        velX = 0;
    } else if (posX < 0) {
        posX = 0;
        velX = 0;
    }
    if (posY + hitbox.h > ::SCREEN_HEIGHT) {
        posY = ::SCREEN_HEIGHT - hitbox.h;
        velY = 0;
    } else if (posY < 0) {
        posY = 0;
        velY = 0;
    }

    // set position
    hitbox.x = posX;
    hitbox.y = posY;

    // set rotation to mouse
    SDL_GetMouseState(&mouseX, &mouseY);
    dx = mouseX - (posX + hitbox.w / 2);
    dy = mouseY - (posY + hitbox.h / 2);;
    theta = atan2(dy, dx);

    // attack speed
    if (++atkSpd % 10 == 0 && shooting) {
        calculateBulletVelocity();
        bulletX = posX + hitbox.w / 2 + ((5 + hitbox.w / 2) * cos(theta));
        bulletY = posY + hitbox.w / 2 + ((5 + hitbox.w / 2) * sin(theta));
        bulletList.push_back(Bullet(bulletX, bulletY, bulletAccelX, bulletAccelY));
    }
}


void Player::render(SDL_Renderer* render, SDL_Texture* sprite) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderCopyEx(render, sprite, NULL, &hitbox, theta * (180 / M_PI), NULL, SDL_FLIP_NONE);
}

void Player::handleEvents(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
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
}

void Player::lowerHp() {
    --hp;
}

void Player::free() {
    velX = 0;
    velY = 0;
}

void Player::calculateBulletVelocity() {
    bulletAccelX = cos(theta) * .5;
    bulletAccelY = sin(theta) * .5;
}

void Player::removeBullet(int i) {
    std::swap(bulletList[i], bulletList.back());
    bulletList.pop_back();
}

const SDL_Rect& Player::getRect() const {
    return hitbox;
}
