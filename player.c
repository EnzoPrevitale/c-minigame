#include "headers/header.h"
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

void move(Player *player) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_CONTROLLERBUTTONDOWN) {
            if(e.cbutton.button == LEFT) {
                player->x--;
            } else if (e.cbutton.button == RIGHT) {
                player->x++;
            } else if (e.cbutton.button == UP) {
                player->y++;
            } else if (e.cbutton.button == DOWN){
                player->y--;
            }
            printf("%d, %d\n", player->x, player->y);
        }
    }
}
