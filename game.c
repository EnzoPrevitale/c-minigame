#include "headers/header.h"
#include "headers/game.h"
#include "player.c"

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
    move(game->player);
}
