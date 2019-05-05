#ifndef BULLET_H
#define BULLET_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Bullet {
    public:
        Bullet(int x = 0, int y = 0, double vX = 0.0, double vY = 0.0);
        ~Bullet();
        void update();
        void render(SDL_Renderer* render);
	void subpixel();
        void free();
        const SDL_Rect& GetRect() const;

        void setRemoveStatus(bool status) { removeStatus = status; }
        bool isRemovable() { return removeStatus; }

    private:
        SDL_Rect hitbox;
	//direct x and y positions
        int posX;
        int posY;
	//amount of pixels a bullet should move per frame
        double velX;
        double velY;
	//the amount of sub-pixels the bullet has traveled, used to calculate non integer speeds
	double subX;
	double subY;

        bool removeStatus;
};

#endif
