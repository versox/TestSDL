#ifndef BALL_H
#define BALL_H

#include <stdlib.h>
#include <iostream>
#include "GameWindow.h"
#include "Sprite.h"
#include "Object.h"

class Ball : public Object {
public:
  Ball(GameWindow* window, Sprite* sprite, int x, int y);
  virtual ~Ball();
  void start();
  void update();
  void contact();
private:
  int velX;
  int velY;
  bool moving;
};

#endif
