#include <iostream>
#include "Game.h"
#include "PongGame.h"

#ifdef main
# undef main
#endif

int main(int argc, char* args[]) {
    std::cout << "hi" << std::endl;
    Game* g = new PongGame();
  g->loop();
  delete g;
  return 0;
}
