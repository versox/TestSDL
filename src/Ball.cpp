#include "Ball.h"

Ball::Ball(GameWindow* window, Sprite* sprite, int x, int y)
: Object(window, sprite, x, y) {
    velX = 0;
    velY = 0;
    moving = false;
}

Ball::~Ball() {
}

void Ball::start() {
  if(!moving) {
    // true is +'ve direction
    // false is -'ve direction
    bool direction = (bool) (rand() % 2);
    if(direction) {
      velX = 3;
    } else {
      velX = -3;
    }
    if((rand() % 2)) {
      velY = 1;
    } else {
      velY = -1;
    }
    moving = true;
  }
}

void Ball::update() {
  if(x > 1000 || x < 0) {
    velX = -velX;
  }
  if(y > 500 || y < 0) {
    velY = -velY;
  }
  this->x += velX;
  this->y += velY;
}

void Ball::contact() {
  velX = -velX;
}
