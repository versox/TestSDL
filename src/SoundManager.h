#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <iostream>
#include "SDL_mixer.h"

class SoundManager {
public:
  SoundManager();
  virtual ~SoundManager();
  void playBoop();
  void playBeep();
  void playYay();
private:
  Mix_Chunk* boop;
  Mix_Chunk* beep;
  Mix_Chunk* yay;
};

#endif
