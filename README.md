# TestSDL

A project for testing out SDL and getting ideas for a game / game engine.

Notes:
(SDL_Keysym)
  - Keycode is based off keyboard layout and unicode
  - Scancode is based off physical position of keys

(Passing function pointers)
  Object myObject(NULL, 0, 0);
  eventHandler->registerKey(SDLK_SPACE, myObject, &Object::test);
