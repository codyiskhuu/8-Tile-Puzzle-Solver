#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>
using namespace std;
#include <vector>

class board{
  friend class tree;
  private:
    //int arr[3][3];//holds the board
    int arr[3][3] = {1, 2, 3,
                     0, 5, 6, 
                     4, 7, 8};
    int goal[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 0};//goal state
    bool validMove(char c);//return true if its within the board// when c = 'w' (checks up) | c = 's' (checks down) | c = 'a' (checks left) | c = 'd' (checks right)
    // int row = 1;//encapsulates 0-2
    // int col = 1;//encapsulates 0-2
    int row=1;
    int col=0;
    int depth = 0;
    int score;
    board operator= (const board& b);
    //when we create a new node for tree; copy it then do the move left and right stuff
    
    board* up;
    board* down;
    board* left;
    board* right;
    
    

  public:
    board();//create goalstate board 1-8 | 0 = blank space
    board(board* );
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void display();//displays the current board
    //void legalMoves();//provides legal moves
    vector<char> legalMoves();
    int heuristics(int heuristic);
    
    board* prev;
    void addScore(int h, int d);
    string getHash();
    string getHashGoal();
};






#endif
