#include "PongGame.h"

PongGame::PongGame() : Game("Pong", 1000, 500) {
  //Black background
  SDL_Color backgroundColor = {
    0, 0, 0, 0
  };
  getGameWindow()->setWindowColor(backgroundColor);

  redPaddleSprite = new Sprite("redPaddle.png", 0.2);
  bluePaddleSprite = new Sprite("bluePaddle.png", 0.2);
  ballSprite = new Sprite("ball.png", 0.2);
  playerOne = new Object(getGameWindow(), redPaddleSprite, 150, 200);
  playerTwo = new Object(getGameWindow(), bluePaddleSprite, 850, 200);
  ballObject = new Object(getGameWindow(), ballSprite, 500, 250);
}

PongGame::~PongGame() {

}
