#include "game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

static SDL_Renderer* renderer = nullptr;

Ship s;

std::vector<Rock> rockList;
std::vector<Rock>::iterator rockItr;

Game::Game() {
    quit = false;
    window = NULL;
    for (int i = 0; i < 1; ++i) {
        rockList.push_back(Rock());
    }
}

Game::~Game() {
    close();
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
    SDL_PollEvent(&e);
    switch (e.type) {
        case SDL_QUIT:
            quit = true;
            break;
        default:
            break;
    }
    s.handleEvents(e);
}

void Game::update() {

    s.update();
    for (int i = 0; i < s.getBulletListSize(); ++i) {
        s.bulletUpdate(i);
        if (s.bulletIsRemovable(i)) {
            s.removeBullet(i);
            break;
        }
    }
    for (int i = 0; i < rockList.size(); ++i) {
        rockList[i].update();
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
