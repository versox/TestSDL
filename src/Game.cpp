#include "Game.h"

Game::Game(char* title) {
  this->title = title;
  init();
  initWindows();
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

int Game::initRenderer(){
    renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

int Game::loop() {
  bool quit = false;
  while(!quit) {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
      if(event.type == SDL_QUIT) {
        quit = true;
      }
    }
  }
  return 0;
}

Game::~Game() {
  end();
}

void Game::end() {
    delete window;
  SDL_Quit();
}
