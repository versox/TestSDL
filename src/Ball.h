#ifndef BALL_H
#define BALL_H

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "GameWindow.h"
#include "Sprite.h"
#include "Object.h"
#include "Paddle.h"

class Ball : public Object {
public:
  Ball(GameWindow* window, Sprite* sprite, int x, int y, std::vector<Paddle*>* paddles);
  virtual ~Ball();
  void reset();
  void start();
  void update();
private:
  int initX;
  int initY;
  int velX;
  int velY;
  bool moving;
  std::vector<Paddle*>* paddles;
};

#endif
