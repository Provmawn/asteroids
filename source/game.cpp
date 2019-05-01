#include "game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

static SDL_Renderer* renderer = nullptr;

Ship* s;

std::vector<Rock*> rockList;
std::vector<Rock*>::iterator rockItr;
//std::vector<Bullet*> bulletList;
//std::vector<Bullet*>::iterator bulletItr;

Game::Game() {
    quit = false;
    window = NULL;
    s = new Ship();
    for (int i = 0; i < 10; ++i) {
        rockList.push_back(new Rock());
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
    s->handleEvents(e);
}

void Game::update() {
    s->update();
    for (rockItr = rockList.begin(); rockItr != rockList.end(); ++ rockItr) {
        (*rockItr)->update();
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
    s->render(renderer);
    for (rockItr = rockList.begin(); rockItr != rockList.end(); ++ rockItr) {
        (*rockItr)->render(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Game::close() {
    delete s;
    for (rockItr = rockList.end(); rockItr != rockList.begin(); --rockItr) {
        (*rockItr)->free();
    }
    rockList.clear();
    IMG_Quit();
    SDL_Quit();
}
