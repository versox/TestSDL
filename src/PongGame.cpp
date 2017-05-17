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
  playerOne = new Paddle(getGameWindow(), redPaddleSprite, 150, 200);
getEventHandler()->registerKey(SDLK_w, *playerOne, (static_cast<void (Object::*)()>(&Paddle::moveUp)));
getEventHandler()->registerKey(SDLK_s, *playerOne, (static_cast<void (Object::*)()>(&Paddle::moveDown)));
  playerTwo = new Paddle(getGameWindow(), bluePaddleSprite, 850, 200);
  getEventHandler()->registerKey(SDLK_UP, *playerTwo, (static_cast<void (Object::*)()>(&Paddle::moveUp)));
  getEventHandler()->registerKey(SDLK_DOWN, *playerTwo, (static_cast<void (Object::*)()>(&Paddle::moveDown)));
  ballObject = new Object(getGameWindow(), ballSprite, 500, 250);
}

PongGame::~PongGame() {

}