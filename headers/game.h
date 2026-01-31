#ifndef GAME
#define GAME

#include "player.h"

typedef struct {
    int running;
    Player *player;
} Game;

void tick(Game *game);

#endif
