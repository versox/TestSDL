#include "Game.h"

Game::Game(std::string title) {
  this->title = title;
  init();
  initWindows();

  eventHandler = new EventHandler(this);
  sprite = new Sprite("train.png");
  obj = new Object(window, sprite, 0, 0);
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
  window = new GameWindow();
  window->initWindow();
  window->initRenderer();
}

int Game::loop() {
  quitGame = false;
  while(!quitGame) {
    eventHandler->handle();
    window->render();
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
  IMG_Quit();
  SDL_Quit();
}
