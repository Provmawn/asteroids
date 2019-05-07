#include "timer.h"

Timer::Timer()
    : start_ticks_(0), pause_ticks_(0), paused(false), started(false)
{}

Timer::~Timer() {

}

void Timer::start() {
    started = true;
    start_ticks_ = SDL_GetTicks();
}

void Timer::stop() {
    paused = false;
    started = false;
    start_ticks_ = 0;
    pause_ticks_ = 0;
}

void Timer::pause() {
    paused = true;
    pause_ticks_ = SDL_GetTicks() - start_ticks_;
    start_ticks_ = 0;
}

void Timer::unpause() {
    paused = false;
    start_ticks_ = SDL_GetTicks() - pause_ticks_;
    pause_ticks_ = 0;
}

uint32_t Timer::getTicks() {
    if (started) {
        if (paused) {
            return pause_ticks_;
        } else {
            return SDL_GetTicks() - start_ticks_;
        }
    }
    return 0;
}


