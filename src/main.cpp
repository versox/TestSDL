#include <iostream>
#include "Game.h"
#include "PongGame.h"

#ifdef main
# undef main
#endif

int main(int argc, char* args[]) {
    Game* g = new PongGame();
    g->loop();
    delete g;
    return 0;
}
