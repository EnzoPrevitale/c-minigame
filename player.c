#include "headers/header.h"
#include <SDL2/SDL_events.h>
#include "headers/player.h"

#define CROSS 0
#define CIRCLE 1
#define SQUARE 2
#define TRIANGLE 3
#define MEDIA 4
#define CENTER 5
#define MENU 6
#define L3 7
#define R3 8
#define L1 9
#define R1 10
#define UP 11
#define DOWN 12
#define LEFT 13
#define RIGHT 14
#define UP_DIR 1
#define RIGHT_DIR 2
#define DOWN_DIR 3
#define LEFT_DIR 4

void move(Player *player) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_CONTROLLERBUTTONDOWN) {
            if(e.cbutton.button == LEFT) {
                player->dir = LEFT_DIR;
            } else if (e.cbutton.button == RIGHT) {
                player->dir = RIGHT_DIR;
            } else if (e.cbutton.button == UP) {
                player->dir = UP_DIR;
            } else if (e.cbutton.button == DOWN){
                player->dir = DOWN_DIR;
            }
            player->move = 1;
        } else if (e.type == SDL_CONTROLLERBUTTONUP) {
            player->move = 0;
        }
    }

    if(player->move) {
        if(player->dir == LEFT_DIR) {
            player->x--;
        } else if (player->dir == RIGHT_DIR) {
            player->x++;
        } else if (player->dir == UP_DIR) {
            player->y--;
        } else if (player->dir == DOWN_DIR){
            player->y++;
        }
    }
}
