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
    std::cout << direction << std::endl;
  }
}

void Ball::update() {
  this->x += velX;
  this->y += velY;
}

void Ball::contact() {

}
