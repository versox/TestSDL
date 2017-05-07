#include "Game.h"

Game::Game(char* title) {
  this->title = title;
  init();
  initWindows();
}

int Game::init() {
  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
      std::cout << "Error Initializing SDL: " << SDL_GetError() << std::endl;
      return 1;
  }
  return 0;
}

int Game::initWindows() {
  GameWindow* mainWindow = new GameWindow();
  mainWindow->initWindow();
  windows.push_back(mainWindow);
}

int Game::loop() {
  quit = false;
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

int Game::end() {
  std::cout << windows.size() << std::endl;
  for(int i = 0; i < windows.size(); i++) {
    delete windows[i];
  }
  SDL_Quit();
}
