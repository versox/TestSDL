#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(GameWindow * window, int x1, int y1, int x2, int y2)
: Object(window, NULL, 0, 0) {
  setup();
  playerOneX = x1;
  playerOneY = y1;
  playerOneScore = 0;
  playerTwoX = x2;
  playerTwoY = y2;
  playerTwoScore = 0;
}

ScoreBoard::~ScoreBoard() {

}

void ScoreBoard::setup() {
  numbers.push_back(new Sprite("zero.png", 0.2));
  numbers.push_back(new Sprite("one.png", 0.2));
  numbers.push_back(new Sprite("two.png", 0.2));
  numbers.push_back(new Sprite("three.png", 0.2));
  numbers.push_back(new Sprite("four.png", 0.2));
  numbers.push_back(new Sprite("five.png", 0.2));
  numbers.push_back(new Sprite("six.png", 0.2));
  numbers.push_back(new Sprite("seven.png", 0.2));
  numbers.push_back(new Sprite("eight.png", 0.2));
  numbers.push_back(new Sprite("nine.png", 0.2));
  for(unsigned int i = 0; i < numbers.size(); i++) {
    numbers[i]->setup(window, window->getRenderer());
  }
}

void ScoreBoard::render() {
  numbers[playerOneScore]->render(playerOneX, playerOneY, 1);
  numbers[playerTwoScore]->render(playerTwoX, playerTwoY, 1);
}

void ScoreBoard::increaseScore(int player) {
  if(player == 1) {
    playerOneScore++;
    if(playerOneScore > 9) {
      std::cout << "Player 1 win!" << std::endl;
      resetScore();
    }
  }
  if(player == 2) {
    playerTwoScore++;
    if(playerTwoScore > 9) {
      std::cout << "Player 2 win!" << std::endl;
      resetScore();
    }
  }
}

void ScoreBoard::resetScore() {
  playerOneScore = 0;
  playerTwoScore = 0;
}
