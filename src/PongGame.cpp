#include "PongGame.h"

PongGame::PongGame() : Game("Pong", 1000, 500) {
  //Setup a random seed
  srand(time(NULL));

  //Black background
  SDL_Color backgroundColor = {
    0, 0, 0, 0
  };
  getGameWindow()->setWindowColor(backgroundColor);

  //Get window size
  int windowWidth = getGameWindow()->getWidth();
  int windowHeight = getGameWindow()->getHeight();

  //Sprites
  redPaddleSprite = new Sprite("redPaddle.png", 0.2);
  bluePaddleSprite = new Sprite("bluePaddle.png", 0.2);
  ballSprite = new Sprite("ball.png", 0.2);
  //Scoreboard
  scoreBoard = new ScoreBoard(getGameWindow(), windowWidth / 3, windowHeight /2, windowWidth - (windowWidth / 3), windowHeight / 2);
  //Players
  playerPaddles = new std::vector<Paddle*>;
  //Player One
  playerPaddles->push_back(new Paddle(getGameWindow(), redPaddleSprite, windowWidth / 8, windowHeight / 2));
  getEventHandler()->registerKey(SDLK_w, *(*playerPaddles)[0], (static_cast<void (Object::*)()>(&Paddle::moveUp)));
  getEventHandler()->registerKey(SDLK_s, *(*playerPaddles)[0], (static_cast<void (Object::*)()>(&Paddle::moveDown)));
  //Player Two
  playerPaddles->push_back(new Paddle(getGameWindow(), bluePaddleSprite, windowWidth - (windowWidth / 8), windowHeight / 2));
  getEventHandler()->registerKey(SDLK_UP, *(*playerPaddles)[1], (static_cast<void (Object::*)()>(&Paddle::moveUp)));
  getEventHandler()->registerKey(SDLK_DOWN, *(*playerPaddles)[1], (static_cast<void (Object::*)()>(&Paddle::moveDown)));
  //Ball
  ballObject = new Ball(getGameWindow(), ballSprite, windowWidth / 2, windowHeight / 2, playerPaddles, scoreBoard);
  getEventHandler()->registerKey(SDLK_SPACE, *ballObject, (static_cast<void (Object::*)()>(&Ball::start)));
  getEventHandler()->registerKey(SDLK_r, *ballObject, (static_cast<void (Object::*)()>(&Ball::reset)));

  //Start Game Loop
  this->loop();
}

PongGame::~PongGame() {

}
