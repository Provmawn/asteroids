#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
#include <vector>
#include "player.h"
#include "asteroid.h"
#include "bullet.h"
#include "timer.h"


class Game {
    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        bool loadMedia(); 
        void handleEvents();
        void update();
        void render();
        void close();

        bool running() { return !quit; }
        const SDL_Rect& getCamera() const { return camera; }

    private:
        void update_framerate();
        SDL_Rect camera;
        SDL_Texture* loadFromFile(std::string path);
        Player player;
        std::vector<Asteroid> asteroids;

        float fps;
        unsigned int counted_frames;
        bool quit;
        SDL_Window* window;
        Timer framerate_timer;
        std::unordered_map<std::string, SDL_Texture*> assets;
};
#endif
