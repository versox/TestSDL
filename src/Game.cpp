#include "Game.h"

Game::Game(char* title) {
  this->title = title;
  init();
  initWindows();

  eventHandler = new EventHandler(this);
}

bool Game::init() {
    bool success = true;
  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
      std::cout << "Error Initializing SDL: " << SDL_GetError() << std::endl;
      success=false;
  }
  return success;
}

int Game::initWindows() {
  GameWindow* mainWindow = new GameWindow();
  mainWindow->initWindow();
}

int Game::loop() {
  quitGame = false;
  while(!quitGame) {
    eventHandler->handle();
  }
  return 0;
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
  SDL_Quit();
}
