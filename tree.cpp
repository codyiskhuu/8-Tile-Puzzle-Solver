#include <iostream>
using namespace std;
#include "tree.h"
#include "board.h"

tree :: tree(){
  root = new board();//intialize new board
  root->display();
  curr = root;
  
}

void tree :: goUp(){//root tree
 if(curr->validMove('w')) {
    board* temp = new board(curr);//create new temp
    temp->moveUp();//temp move up
    curr->up=temp;//set current up to new moved temp
    //now switch current to the one we just moved too
    curr = temp;
    temp = NULL;//set to null then delete temp
    delete temp;
 } 
}

void tree :: goDown(){//root tree
  if(curr->validMove('s')) {
    board* temp = new board(curr);//create new temp
    temp->moveDown();//temp move up
    curr->down=temp;//set current up to new moved temp
    //now switch current to the one we just moved too
    curr = temp;
    temp = NULL;//set to null then delete temp
    delete temp; 
  }
}
void tree :: goLeft(){//root tree
  if(curr->validMove('a')) {
    board* temp = new board(curr);//create new temp
    temp->moveLeft();//temp move up
    curr->left=temp;//set current up to new moved temp
    //now switch current to the one we just moved too
    curr = temp;
    temp = NULL;//set to null then delete temp
    delete temp; 
  }
}
void tree :: goRight(){//root tree
  if(curr->validMove('d')) {
    board* temp = new board(curr);//create new temp
    temp->moveRight();//temp move up
    curr->right=temp;//set current up to new moved temp
    //now switch current to the one we just moved too
    curr = temp;
    temp = NULL;//set to null then delete temp
    delete temp; 
  }
}
void tree :: displayBoard(){
  cout<<"Displaying From the Root"<<endl;
  root->display();
  displayBoard(root);
}

void tree :: displayBoard(board* cur){
  if(cur->up != 0){
    cout<<"went up"<<endl;
    cur->up->display();
    displayBoard(cur->up); 
  }
  else if(cur->down != 0){
    cout<<"went down"<<endl;
    cur->down->display();
    displayBoard(cur->down); 
  }
  else if(cur->left != 0){
    cout<<"went left"<<endl;
    cur->left->display();
    displayBoard(cur->left); 
  }
  else if(cur->right != 0){
    cout<<"went right"<<endl;
    cur->right->display();
    displayBoard(cur->right); 
  }
}