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
  Game(std::string title = "Generic Game", int width = 1000, int height = 750);
  virtual ~Game();
  int loop();
  void quit();
  GameWindow* getGameWindow();
  EventHandler* getEventHandler();
private:
  /*Sprite* sprite;
  Object* obj;*/

  unsigned int lastTime = 0, currentTime;

  int width;
  int height;

  std::string title;
  GameWindow* window;
  EventHandler* eventHandler;
  bool quitGame;

  bool init();
  void initWindows();

  void end();
};

#endif
