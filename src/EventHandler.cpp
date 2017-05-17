#include "EventHandler.h"

EventHandler::EventHandler(Game* game) {
  this->game = game;
  keystate = SDL_GetKeyboardState(NULL);
}

void EventHandler::handle() {
  while(SDL_PollEvent(&event) != 0) {
    switch(event.type) {
      case SDL_QUIT:
        game->quit();
        break;
    }
  }
  handleKey();
}

void EventHandler::handleKey() {
  for(unsigned int i = 0; i < registeredKeys.size(); i++) {
    RegisteredKey rKey = registeredKeys[i];
    SDL_Keycode key = std::get<0>(rKey);
    SDL_Scancode scancode = SDL_GetScancodeFromKey(key);
    if(keystate[scancode]) {
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
