#include "headers/header.h"
#include "headers/game.h"
#include "player.c"

int init(Game *game) {
    game->running = 1;
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

void render(Game *game) {
    system("clear");
    for(int y = 0; y < 15; y++) {
        for(int x = 0; x < 100; x++) {
            if(x == (int)game->player->x && y == (int)game->player->y) {
                printf("%d", game->player->dir);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
