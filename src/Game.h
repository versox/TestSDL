#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "GameWindow.h"

class Game {
public:
  Game(char* title = "Generic Game");
  virtual ~Game();
  int loop();
private:
  const char* title;
  std::vector<GameWindow*> windows;
  bool quit;

  int init();
  virtual int initWindows();

  int end();
};

#endif
