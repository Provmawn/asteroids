#include "bullet.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


Bullet::Bullet(int x, int y, double vx, double vy) 
    : posX(x), posY(y), velX(vx), velY(vy), subX(0), subY(0), removeStatus(false)
{
    hitbox.x = 0;
    hitbox.y = 0;
    hitbox.w = 5;
    hitbox.h = 5;
}

Bullet::~Bullet() {

}

void Bullet::update() {
//update subpixel movement
    posX += velX;
    posY += velY;
//move hitbox to reflect current position
    hitbox.x = posX + hitbox.w / 2;
    hitbox.y = posY + hitbox.h / 2;
//destroy bullets that exist the screen
    if (posX < 0 || posX + hitbox.w > ::SCREEN_WIDTH ||
       posY < 0 || posY + hitbox.h > ::SCREEN_HEIGHT) {
        removeStatus = true;
    }
}

void Bullet::subpixel() {
	//assume signs of movement are positive
	    int signX = copysign(1.0,velX);
	    int signY = copysign(1.0,velY);
	//move subpixel amount forward by velocity
		subX += velX;
		subY += velY;
	//change actual position whenever subpixels exceed 1
	while( abs(subX) >= 1 ) {
		posX += signX;
		subX -= signX;
	}
	while( abs(subY) >= 1 ) {
		posY += signY;
		subY -= signY;
	}
}

void Bullet::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}

void Bullet::free() {
//change this to destroy/deallocate bullets?
}

const SDL_Rect& Bullet::getRect() const {
    return hitbox;
}

