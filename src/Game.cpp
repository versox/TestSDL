#include "Game.h"

Game::Game(std::string title, int width, int height) {
  this->title = title;
  this->width = width;
  this->height = height;
  init();
  initWindows();
  eventHandler = new EventHandler(this);
}

bool Game::init() {
  bool success = true;

  //Make it possible to render png images
  int imgFlags = IMG_INIT_PNG;
  IMG_Init( imgFlags );

  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
      std::cout << "Error Initializing SDL: " << SDL_GetError() << std::endl;
      success=false;
  }

  return success;
}

void Game::initWindows() {
  window = new GameWindow(title, width, height);
  window->initWindow();
  window->initRenderer();
}

int Game::loop() {
  quitGame = false;
  while(!quitGame) {
    currentTime = SDL_GetTicks();
    if(currentTime > lastTime + 10) {
      Object::updateObjects();
      eventHandler->handle();
      window->render();
      lastTime = currentTime;
    }
  }
  return 0;
}

GameWindow* Game::getGameWindow() {
  return window;
}

EventHandler* Game::getEventHandler() {
  return eventHandler;
}

void Game::quit() {
  quitGame = true;
}

Game::~Game() {
  delete eventHandler;
  end();
}

void Game::end() {
    delete window;
  IMG_Quit();
  SDL_Quit();
}
