#include "GameWindow.h"

GameWindow::GameWindow() {
  windowTitle = "Hello world";
  x = SDL_WINDOWPOS_UNDEFINED;
  y = SDL_WINDOWPOS_UNDEFINED;
  width = 500;
  height = 500;
}

GameWindow::~GameWindow() {
  SDL_DestroyWindow(window);
}

int GameWindow::initWindow() {
  if(createWindow() != 0) {
    return 1;
  }
  return 0;
}

SDL_Window* GameWindow::getWindow() {
  return window;
}

int GameWindow::createWindow() {
  window = SDL_CreateWindow(windowTitle, x, y, width, height, SDL_WINDOW_OPENGL);
  if(window == nullptr) {
    std::cout << "Window Initialize Error: (" << windowTitle << ") " << SDL_GetError() << std::endl;
    return 1;
  }
  return 0;
}
