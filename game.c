#include <SDL2/SDL.h>

#include "headers/game.h"

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

int init(Game *g) {
    SDL_Init(SDL_INIT_GAMECONTROLLER);

    if(SDL_NumJoysticks() < 1) {
        printf("Não foi possível encontrar o controle.\n");
        return 1;
    }

    SDL_GameController *ctrl = SDL_GameControllerOpen(0);
    printf("Controle conectado!\n");
    return 0;
}

void tick(Game *game) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_CONTROLLERBUTTONDOWN) {
            printf("%d\n", e.cbutton.button);
        }
    }
}
