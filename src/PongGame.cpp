#include "PongGame.h"

PongGame::PongGame() : Game("Pong") {
  redPaddleSprite = new Sprite("redPaddle.png");
  bluePaddleSprite = new Sprite("bluePaddle.png");
  ballSprite = new Sprite("ball.png");
}

PongGame::~PongGame() {

}
