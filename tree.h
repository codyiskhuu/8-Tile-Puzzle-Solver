#ifndef __TREE_H__
#define __TREE_H__
#include "board.h"

class tree{
  private:
  board* root;
  board* curr;
  public:
  tree();
  
  void goUp();
  void goDown();
  void goLeft();
  void goRight();
  void displayBoard();
  void displayBoard(board* cur);
  //what i want is to basically hold all states using tree
  //check up to four times i guess
};


#endif
/*
function general-search(problem, QUEUEING-FUNCTION)  
nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE)) 
loop do
 if EMPTY(nodes) then return "failure" 
   node = REMOVE-FRONT(nodes) 
 if problem.GOAL-TEST(node.STATE) succeeds then return node
    nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))  
 end
*/