#ifndef BULLETS_H
#define BULLETS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Bullets {
    public:
        Bullets();
        ~Bullets();
        void update();
        void render(SDL_Renderer* render);
	void subpixel();
        void free();
        const SDL_Rect& GetRect()const;

    private:
        SDL_Rect hitbox;
	//direct x and y positions
        int posX;
        int posY;
	//amount of pixels a bullet should move per frame
        float velX;
        float velY;
	//the amount of sub-pixels the bullet has traveled, used to calculate non integer speeds
	float subX;
	float subY;
};

#endif
