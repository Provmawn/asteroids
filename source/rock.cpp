#include "rock.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;



Rock::Rock() {
    hitbox.x=0;
    hitbox.y=0;
    hitbox.w=10;
    hitbox.h=10;
<<<<<<< HEAD:source/rocks.cpp
    posX = 0;
    posY = 0;
    velX = 1;
    velY = 1;
    subX = 0;
    subY = 0;
=======
    posX = ::SCREEN_WIDTH / 2;
    posY = ::SCREEN_HEIGHT / 2;
    std::cout << __FILE__ << ": constructor..." << std::endl;
    velX = (rand() % 10) + 1;
    velY = (rand() % 10) + 1;
>>>>>>> ce85b607010d22b2176ba3edfaabb65e9e5ec8a4:source/rock.cpp
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

<<<<<<< HEAD:source/rocks.cpp
void Rocks::subpixel() {
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



void Rocks::render(SDL_Renderer* render) {
=======
void Rock::render(SDL_Renderer* render) {
>>>>>>> ce85b607010d22b2176ba3edfaabb65e9e5ec8a4:source/rock.cpp
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(render, &hitbox);
}


void Rock::free() {
    delete this;
}

const SDL_Rect& Rock::GetRect()const{

return hitbox;


}
