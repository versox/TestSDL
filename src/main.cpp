#include "Game.h"

int main(int argc, char* args[]) {
  Game* g = new Game();
  g->loop();
  delete g;
  return 0;
}
