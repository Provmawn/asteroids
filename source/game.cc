#include "game.h"

static SDL_Renderer* renderer = nullptr;


Game::Game() 
    : quit(false), counted_frames(0), fps(0.0f), window(NULL)
{
    for (int i = 0; i < 20; ++i) {
        asteroids.push_back(Asteroid());
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
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

bool Game::loadMedia() {
    bool success = true;

    SDL_Texture* texture;
    if ((texture = loadFromFile("../resources/ship.png")) == nullptr) {
        std::cerr << "Unable to load ship" << std::endl;
        success = false;
    }
    assets.insert(std::make_pair("ship", texture));

    if ((texture = loadFromFile("../resources/ship_thrust.png")) == nullptr) {
        std::cerr << "Unable to load ship" << std::endl;
        success = false;
    }
    assets.insert(std::make_pair("ship_thrust", texture));

    return success;
}

SDL_Texture* Game::loadFromFile(std::string path) {
    SDL_Texture* loadedTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
    } else {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0x00, 0xFF));
        loadedTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (loadedTexture == nullptr) {
            std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return loadedTexture;

}

void Game::handleEvents() {
    static SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            quit = true;
            return;
        }
        if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
            player.handleEvents(e);
        }
    }
}

void Game::update_framerate() {
    framerate_timer.start();
    fps = counted_frames / (framerate_timer.getTicks() / 1000.f);
    if (fps > 200000) {
        fps = 0;
    }
    ++counted_frames;
    int frameTicks = framerate_timer.getTicks();
    if (frameTicks < 1000 / 60) {
        SDL_Delay(1000 / 60 - frameTicks);
    }                                                    
}

void Game::update() {

    update_framerate();

    player.update();    // player

    for (int i = 0; i < asteroids.size(); ) {   // asteroids
        asteroids[i].update();
        if (SDL_HasIntersection(&(asteroids[i].getRect()), &(player.getRect())) == SDL_TRUE) {
            player.lowerHp();
            std::swap(asteroids[i], asteroids.back());
            asteroids.pop_back();
            continue;
        }
        ++i;
    }
    std::vector<Bullet>& bullets = player.getBullets();
    for (int i = 0; i < bullets.size(); ) {
        bullets[i].update();
        for (int j = 0; j < asteroids.size(); ) {
            if (SDL_HasIntersection(&(player.getBulletHitbox(i)), &(asteroids[j].getRect())) == SDL_TRUE) {
                bullets[i].setRemoveStatus(true);

                std::swap(asteroids[j], asteroids.back());
                asteroids.pop_back();
                continue;
            }
            ++j;
        }
        if (bullets[i].isRemovable()) {
            player.removeBullet(i);
            continue;
        }
        ++i;
    }
}
void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    if (player.isMoving()) {
        player.render(renderer, (assets.find("ship_thrust"))->second);
    } else {
        player.render(renderer, (assets.find("ship"))->second);
    }
    std::vector<Bullet>& bullets = player.getBullets();
    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i].render(renderer);
    }
    for (int i = 0; i < asteroids.size(); ++i) {
        asteroids[i].render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::close() {
    asteroids.clear();
    IMG_Quit();
    SDL_Quit();
}
