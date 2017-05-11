#include "EventHandler.h"

EventHandler::EventHandler(Game* game) {
  this->game = game;
}

void EventHandler::handle() {
  while(SDL_PollEvent(&event) != 0) {
    switch(event.type) {
      case SDL_QUIT:
        game->quit();
        break;
      case SDL_KEYDOWN:
        std::cout << "Key down" << std::endl;
        break;
    }
  }
}

void EventHandler::registerKey(SDL_Keycode key, Object& obj, void (Object::*callbackFunc)(void)) {
    (obj.*callbackFunc)();
}

EventHandler::~EventHandler() {

}
