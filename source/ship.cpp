#include "ship.h"

Ship::Ship() {
    hitbox.x = 0;
    hitbox.y = 0;
    hitbox.w = 100;
    hitbox.h = 100;
    posX = 0;
    posY = 0;
    velX = 1;
    velY = 2;
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
const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
if( currentKeyStates[ SDL_SCANCODE_UP ] )
{ posY -= velX; }
if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
{ posY += velY; } 
if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
{ posX -= velX; } 
if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
{ posX += velY; } 
}
void Ship::free() {
    velX = 0;
    velY = 0;
}
