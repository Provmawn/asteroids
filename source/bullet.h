#ifndef BULLET_H
#define BULLET_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Bullet {
    public:
        Bullet(double x = 0.0, double y = 0.0, double ax = 0.0, double ay = 0.0);
        ~Bullet();
        void update();
        void render(SDL_Renderer* render);
	void subpixel();
        void free();
        const SDL_Rect& getRect() const;

        void setRemoveStatus(bool status) { removeStatus = status; }
        bool isRemovable() { return removeStatus; }

    private:
        SDL_Rect hitbox;
	//direct x and y positions
        double posX, posY;
	//amount of pixels a bullet should move per frame
        double velX, velY;
	//the amount of sub-pixels the bullet has traveled, used to calculate non integer speeds
        double accelX, accelY;
	double subX;
	double subY;

        bool removeStatus;
};

#endif
