#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <iostream>
#include <tuple>
#include <vector>
#include "SDL.h"
#include "Game.h"
#include "Object.h"

class Game;

class EventHandler {
public:
  typedef std::tuple<SDL_Keycode, Object*, void (Object::*) ()> ERegister;
    
  EventHandler(Game* game);
  virtual ~EventHandler();

  void handle();
  void registerKey(SDL_Keycode key, Object& obj, void (Object::*callbackFunc)(void));
private:
  Game* game;
  SDL_Event event;
  std::vector<ERegister> registeredEvents;
  
};

#endif
