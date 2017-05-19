#ifndef BALL_H
#define BALL_H

#include "GameWindow.h"
#include "Sprite.h"
#include "Object.h"

class Ball : public Object {
public:
  Ball(GameWindow* window, Sprite* sprite, int x, int y);
  virtual ~Ball();
  void update();
  void setMoving(bool b);
  void contact();
private:
};

#endif
