#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "SDL.h"
#include "Game.h"
#include <iostream>

class Game;

class EventHandler {
public:
  EventHandler(Game* game);
  virtual ~EventHandler();

  void handle();
  void registerKey();
private:
  Game* game;
  SDL_Event event;
};

#endif
