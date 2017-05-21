#include "SoundManager.h"

SoundManager::SoundManager() {
  if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
    std::cout << "Mix OpenAudio error" << std::endl;
  }
  boop = Mix_LoadWAV("boop.wav");
  beep = Mix_LoadWAV("beep.wav");
  yay = Mix_LoadWAV("yay.wav");
}

SoundManager::~SoundManager() {
  Mix_FreeChunk(boop);
  Mix_FreeChunk(beep);
  Mix_FreeChunk(yay);
  Mix_CloseAudio();
}

void SoundManager::playBoop() {
  Mix_PlayChannel(-1, boop, 0);
}

void SoundManager::playBeep() {
  Mix_PlayChannel(-1, beep, 0);
}

void SoundManager::playYay() {
  Mix_PlayChannel(-1, yay, 0);
}
