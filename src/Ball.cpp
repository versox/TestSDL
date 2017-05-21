#include "Ball.h"

Ball::Ball(GameWindow* window, Sprite* sprite, int x, int y, std::vector<Paddle*>* paddles, ScoreBoard* scoreboard, SoundManager* soundManager)
: Object(window, sprite, x, y) {
    setup();
    initX = x;
    initY = y;
    velX = 0;
    velY = 0;
    moving = false;
    this->paddles = paddles;
    this->scoreboard = scoreboard;
    this->soundManager = soundManager;
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

void Ball::reset() {
  moving = false;
  x = initX;
  y = initY;
  velX = 0;
  velY = 0;
}

void Ball::update() {
  // Check Walls
  if(y > 500 || y < 0) {
    velY = -velY;
  }

  // Check Paddles
  int paddleHeight = paddles->at(0)->getSprite()->getActualHeight();
  int paddleWidth = paddles->at(0)->getSprite()->getActualWidth();
  int ballRadius = this->getSprite()->getActualWidth() / 2;
  // Player 1
  // In paddle range?
  if(paddles->at(0)->y - (paddleHeight / 2) < this->y && this->y < paddles->at(0)->y + (paddleHeight / 2)) {
    // Touching paddle
    if(paddles->at(0)->x - (paddleWidth / 2) < this->x + ballRadius && this->x - ballRadius < paddles->at(0)->x + (paddleWidth / 2)) {
      velX = fabs(velX);
      soundManager->playBoop();
    }
  }
  // Player 2
  // In paddle range?
  if(paddles->at(1)->y - (paddleHeight / 2) < this->y && this->y < paddles->at(1)->y + (paddleHeight / 2)) {
    // Touching paddle
    if(paddles->at(1)->x - (paddleWidth / 2) < this->x + ballRadius && this->x - ballRadius < paddles->at(1)->x + (paddleWidth / 2)) {
      velX = -(fabs(velX));
      soundManager->playBeep();
    }
  }

  //Move
  this->x += velX;
  this->y += velY;

  //Score
  if(x < 0) {
    //Player 2 score
    scoreboard->increaseScore(2);
    soundManager->playYay();
    reset();
  }
  if(x > 1000) {
    //Player 1 score
    scoreboard->increaseScore(1);
    soundManager->playYay();
    reset();
  }
}
