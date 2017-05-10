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
  GameWindow window;
  bool quit;

  bool init();
  virtual int initWindows();

  void end();
};

#endif
