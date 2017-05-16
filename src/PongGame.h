#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <string>
#include "Game.h"
#include "Sprite.h"

class PongGame : public Game {
public:
  PongGame();
  virtual ~PongGame();
private:
  Sprite* redPaddleSprite;
  Sprite* bluePaddleSprite;
  Sprite* ballSprite;
};

#endif
