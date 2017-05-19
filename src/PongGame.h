#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include "Game.h"
#include "Sprite.h"
#include "Object.h"
#include "Ball.h"
#include "Paddle.h"
#include "GameWindow.h"
#include "EventHandler.h"

class PongGame : public Game {
public:
  PongGame();
  virtual ~PongGame();
private:
  Sprite* redPaddleSprite;
  Sprite* bluePaddleSprite;
  Sprite* ballSprite;
  Paddle* playerOne;
  Paddle* playerTwo;
  Object* ballObject;
};

#endif
