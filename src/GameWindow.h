#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <iostream>
#include "SDL.h"

class GameWindow {
public:
  GameWindow();
  virtual ~GameWindow();
  int initWindow();
  SDL_Window * getWindow();
private:
  const char* windowTitle;
  int x;
  int y;
  int width;
  int height;
  SDL_Window* window;

  int createWindow();
};

#endif
