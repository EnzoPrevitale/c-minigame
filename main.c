#include "headers/header.h"
#include "game.c"
#include <unistd.h>

int main(){
    Player player = {0, 0};
    Game game = {.player= &player};
    init(&game);

    while(1) {
        tick(&game);
        render(&game);
    }

    return 0;
}