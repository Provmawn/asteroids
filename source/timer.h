#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL.h>

class Timer {
    public:
        Timer();
        ~Timer();
        void start();
        void stop();
        void pause();
        void unpause();

        uint32_t getTicks();
    private:
        uint32_t start_ticks_;
        uint32_t pause_ticks_;
        bool paused;
        bool started;
};

#endif
