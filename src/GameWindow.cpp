#include "GameWindow.h"

GameWindow::GameWindow(std::string title, int width, int height) {
  windowTitle = title;
  x = SDL_WINDOWPOS_UNDEFINED;
  y = SDL_WINDOWPOS_UNDEFINED;
  this->width = width;
  this->height = height;
  windowColor = {
    255, 255, 255, 255
  };
}

GameWindow::~GameWindow() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
}

int GameWindow::initWindow() {
  if(createWindow() != 0) {
    return 1;
  }
  return 0;
}

void GameWindow::initRenderer() {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == NULL) {
    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
  } else {
    SDL_SetRenderDrawColor( renderer, windowColor.r, windowColor.g, windowColor.b, windowColor.a);
  }
}

void GameWindow::render() {
  SDL_RenderClear(renderer);
  //Loop through objects and render them
  std::vector<Object*> objects = Object::getObjects();
  for(unsigned int i = 0; i < objects.size(); i++) {
    objects[i]->render();
  }
  SDL_RenderPresent(renderer);
}

SDL_Window* GameWindow::getWindow() {
  return window;
}

SDL_Renderer* GameWindow::getRenderer() {
  return renderer;
}

void GameWindow::setWindowColor(SDL_Color& windowColor) {
  this->windowColor = windowColor;
  SDL_SetRenderDrawColor( renderer, windowColor.r, windowColor.g, windowColor.b, windowColor.a);
}

int GameWindow::createWindow() {
  window = SDL_CreateWindow(windowTitle.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);
  if(window == nullptr) {
    std::cout << "Window Initialize Error: (" << windowTitle << ") " << SDL_GetError() << std::endl;
    return 1;
  }
  return 0;
}
