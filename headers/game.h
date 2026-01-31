#ifndef GAME
#define GAME

#include "player.h"

typedef struct {
    Player *player;
} Game;

void tick(Game *game);

#endif
