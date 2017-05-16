#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Object.h"

class GameWindow {
public:
  GameWindow(std::string title);
  virtual ~GameWindow();

  virtual int initWindow();
  virtual void initRenderer();

  void render();
  SDL_Window * getWindow();
  SDL_Renderer * getRenderer();
  void setWindowColor(SDL_Color& windowColor);
private:
  std::string windowTitle;
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
