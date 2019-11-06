#include <iostream>
#include "board.h"
#include "tree.h"
using namespace std;




int main() {
  tree t = tree();
  // t.createBoard();
  t.generalSearch(t.root, 1);
  // t.goUp();
  // t.goUp();
  // t.goUp();//not valid
  // t.goDown();
  // t.goDown();
  // t.goLeft();
  // t.goLeft();
  // t.goUp();
  // t.goRight();
  // t.goRight();
  // t.goRight();//not valid

  // t.displayBoard();
  //t.curr->display();

return 0;
}

  // board b = board();
  // b.display();
  // b.legalMoves();
  // b.moveUp();
  // b.moveDown();
  // b.moveUp();
  // b.moveUp();
  // b.moveLeft();
  // b.moveDown();
  // b.legalMoves();
  // b.moveDown();
  // b.legalMoves();
  // b.moveDown();
  // b.moveDown();
  // b.moveLeft();
  // b.moveLeft();
  // b.moveLeft();
  // b.moveRight();
  // b.moveRight();
  // b.moveRight();
  // b.moveRight();
  // b.legalMoves();