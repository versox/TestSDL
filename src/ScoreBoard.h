#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H

#include <iostream>
#include <vector>
#include "GameWindow.h"
#include "Object.h"
#include "Sprite.h"

class ScoreBoard : public Object {
public:
  ScoreBoard(GameWindow * window, int x1, int y1, int x2, int y2);
  virtual ~ScoreBoard();
  void setup();
  void render();
  void increaseScore(int player);
  void resetScore();
private:
  std::vector<Sprite*> numbers;
  int playerOneX;
  int playerOneY;
  int playerOneScore;
  int playerTwoX;
  int playerTwoY;
  int playerTwoScore;
};

#endif
