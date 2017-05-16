#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "SDL.h"
#include "GameWindow.h"
#include "EventHandler.h"
#include "Object.h"

class EventHandler;

class Game {
public:
  Game(std::string title = "Generic Game");
  virtual ~Game();
  int loop();
  void quit();
private:
  Sprite* sprite;
  Object* obj;

  std::string title;
  GameWindow* window;
  EventHandler* eventHandler;
  bool quitGame;

  bool init();
  void initWindows();

  void end();
};

#endif
