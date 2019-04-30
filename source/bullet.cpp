#include "bullet.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


Bullets::Bullets() {
//initialize bullets
    hitbox.x=0;
    hitbox.y=0;
    hitbox.w=2;
    hitbox.h=2;
    posX = 100;
    posY = 100;
    velX = 1.0;
    velY = 1.0;
    subX = 0.0;
    subY = 0.0;
}

Bullets::~Bullets() {
    free();
}

void Bullets::update() {
//update subpixel movement
    subpixel();
//move hitbox to reflect current position
    hitbox.x = posX;
    hitbox.y = posY;
//destroy bullets that exist the screen
    if (posX < 0 || posX + hitbox.w > ::SCREEN_WIDTH) {
        free();
    }
    if (posY < 0 || posY + hitbox.h > ::SCREEN_HEIGHT) {
        free();
    }
}

void Bullets::subpixel() {
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

void Bullets::render(SDL_Renderer* render) {
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}


void Bullets::free() {
//change this to destroy/deallocate bullets?
    velX = 0;
    velY = 0;
}

const SDL_Rect& Bullets::GetRect()const{
    return hitbox;
}
