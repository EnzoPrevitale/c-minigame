#include "headers/header.h"
#include "game.c"
#include <bits/time.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int frames;
long timer;

int64_t timeNano(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000000000LL + ts.tv_nsec;
}

int64_t timeMilli(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000LL + ts.tv_nsec;
}

int main(){
    Player player = {0, 0};
    Game game = {.player = &player};
    init(&game);

    long currentTime;

    long lastTime = timeNano();
    int amountOfTicks = 60;
    double ns = 1000000000 / amountOfTicks;
    double delta = 0;
    frames = 0;
    timer = timeMilli();

    while(game.running) {
        long now = timeNano();
        delta += (now - lastTime) / ns;
        lastTime = now;
        if(delta >= 1) {
            tick(&game);
            render(&game);
        }
    }

    if (timeMilli() - timer >= 1) {
        frames = 0;
        timer += 1000;
    }

    return 0;
}
