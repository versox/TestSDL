#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "GameWindow.h"
#include "EventHandler.h"
#include "Object.h"

class EventHandler;

class Game {
public:
  Game(char* title = "Generic Game");
  virtual ~Game();
  int loop();
  void quit();
private:
  const char* title;
  GameWindow* window;
  EventHandler* eventHandler;
  bool quitGame;

  bool init();
  virtual int initWindows();

  void end();
};

#endif
