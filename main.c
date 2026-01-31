#include "headers/header.h"
#include "game.c"

void render() {
    system("clear");
}

int main(){
    Player player = {0, 0};
    Game game = {.player= &player};
    init(&game);

    while(1) {
        tick(&game);
    }

    return 0;
}