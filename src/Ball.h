#ifndef BALL_H
#define BALL_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "GameWindow.h"
#include "Sprite.h"
#include "Object.h"
#include "ScoreBoard.h"
#include "Paddle.h"
#include "SoundManager.h"

class Ball : public Object {
public:
  Ball(GameWindow* window, Sprite* sprite, int x, int y, std::vector<Paddle*>* paddles, ScoreBoard* scoreboard, SoundManager* soundManager);
  virtual ~Ball();
  void reset();
  void start();
  void update();
private:
  int initX;
  int initY;
  int accelX;
  int accelY;
  int velX;
  int velY;
  bool moving;
  std::vector<Paddle*>* paddles;
  ScoreBoard* scoreboard;
  SoundManager* soundManager;
};

#endif
