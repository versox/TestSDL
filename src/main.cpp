#include <iostream>
#include "Game.h"

#ifdef main
# undef main
#endif

int main(int argc, char* args[]) {
    std::cout << "hi" << std::endl;
    Game* g = new Game();
  g->loop();
  delete g;
  return 0;
}
