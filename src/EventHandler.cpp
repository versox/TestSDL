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
        handleKey();
        break;
    }
  }
}

void EventHandler::handleKey() {
  SDL_Keycode keyCode = event.key.keysym.sym;
  for(int i = 0; i < registeredKeys.size(); i++) {
    RegisteredKey rKey = registeredKeys[i];
    if(keyCode == std::get<0>(rKey)) {
      Object& obj = std::get<1>(rKey);
      void (Object::*callbackFunc)() = std::get<2>(rKey);
      (obj.*callbackFunc)();
    }
  }
}

void EventHandler::registerKey(SDL_Keycode key, Object& obj, void (Object::*callbackFunc)()) {
    registeredKeys.push_back(RegisteredKey(key, obj, callbackFunc));
}

EventHandler::~EventHandler() {

}
