#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "Object.h"

class GameWindow {
public:
  GameWindow();
  virtual ~GameWindow();

  virtual int initWindow();
  virtual void initRenderer();

  void render();
  SDL_Window * getWindow();
  SDL_Renderer * getRenderer();
  void setWindowColor(SDL_Color& windowColor);
private:
  const char* windowTitle;
  int x;
  int y;
  int width;
  int height;
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Color windowColor;

  int createWindow();
};

#endif
