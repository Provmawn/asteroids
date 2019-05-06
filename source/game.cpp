#include "game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

static SDL_Renderer* renderer = nullptr;


Game::Game() {
    quit = false;
    window = NULL;
    for (int i = 0; i < 20; ++i) {
        rockList.push_back(Rock());
    }
}

Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        quit = true;
    } else {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
        if (window == NULL) {
            std::cerr << "Could not create window! SDL Error: " << SDL_GetError() << std::endl;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL) {
                std::cerr << "Could not create renderer! SDL Error: " << SDL_GetError() << std::endl;
            } else {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                int imgFlag = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlag) & imgFlag)) {
                    std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
                }
            }
        }
    }
}

void Game::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e))
        ;
    if (e.type == SDL_QUIT) {
        quit = true;
        return;
    }
    s.handleEvents(e);
}

void Game::update() {

    s.update();
    for (int i = 0; i < rockList.size(); ) {
        rockList[i].update();
        if (SDL_HasIntersection(&(rockList[i].getRect()), &(s.getRect())) == SDL_TRUE) {
            s.lowerHp();
            std::swap(rockList[i], rockList.back());
            rockList.pop_back();
            continue;
        }
        ++i;
    }
    for (int i = 0; i < s.getBulletListSize(); ) {
        s.bulletUpdate(i);
        for (int j = 0; j < rockList.size(); ) {
            if (SDL_HasIntersection(&(s.getBulletHitbox(i)), &(rockList[j].getRect())) == SDL_TRUE) {
                s.setBulletRemoveStatus(i, true);

                std::swap(rockList[j], rockList.back());
                rockList.pop_back();
                continue;
            }
            ++j;
        }
        if (s.bulletIsRemovable(i)) {
            s.removeBullet(i);
            continue;
        }
        ++i;
    }

}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    s.render(renderer);
    for (int i = 0; i < s.getBulletListSize(); ++i) {
        s.bulletRender(i, renderer);
    }
    for (int i = 0; i < rockList.size(); ++i) {
        rockList[i].render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::close() {
    rockList.clear();
    IMG_Quit();
    SDL_Quit();
}
