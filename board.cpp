#include <iostream>
using namespace std;

#include "board.h"

board::board(){
  // int pop = 1;
  
  // for(int i = 0 ; i < 3; ++i){
  //   for(int j = 0; j < 3; ++j){
  //     if(pop != 9){
  //       goal[i][j] = pop;
  //       ++pop;
  //     }
  //     else{
  //       goal[i][j] = 0;
  //     }
       
  //   }
  // }
//cout << row << " " <<col <<endl;
}
board::board(board* nb){
  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      this->arr[i][j] = nb->arr[i][j];
    }
    
  }
  this->row = nb->row;
  this->col = nb->col;
}

void board :: display(){
  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      cout << this->arr[i][j] <<" ";
    }
    cout<<endl;
  }
  cout<<endl;
return; 
}

bool board :: validMove(char c){
  bool valid = false;//default is false
  if(c == 'w'){//move up
    if(row == 0){//row 0 is the top 
      valid = false;
    }
    else{
      valid = true;
    }
  }
  else if(c == 's'){//move down
    if(row ==  2){//row 2 is bottom
      valid = false;
    }
    else{
      valid = true;
    }
  }
  else if(c == 'a'){//move left
    if(col == 0){//col 0 is left
      valid = false;
    }
    else{
      valid = true;
    }
  }
  else if(c == 'd'){//move right
    
    if(col == 2){// col 2 is right
      valid = false;
    }
    else{
      valid = true;
    }
  }

  return valid;
}

void board :: moveUp(){
  if(!validMove('w')){//return true do stuff else dont
    cout <<"Can't Move Up" <<endl;
  }
  else{//swap current pos with row--
    cout<<"Moved Up"<<endl;
    --row;
    int temp = this->arr[row][col];//take row 1 col 2
    arr[row][col] = 0;
    arr[row+1][col] = temp;
    
  }
  //up should now change it
  display();

}

void board :: moveDown(){
  if(!validMove('s')){//return true do stuff else dont
    cout <<"Can't Move Down" <<endl;
  }
  else{//swap current pos with row++
    cout<< "Moved Down"<<endl;
    ++row;
    int temp = arr[row][col];//take row 1 col 2 
    arr[row][col] = 0;
    arr[row-1][col] = temp;
    
  }
  display();

}

void board :: moveLeft(){
  if(!validMove('a')){//return true do stuff else dont
    cout <<"Can't Move Left" <<endl;
  }
  else{//swap current pos with col--
    cout<< "Moved Left"<<endl;
    --col;
    int temp = arr[row][col];//take row 2 col 1 
    arr[row][col] = 0;
    arr[row][col+1] = temp;
    
  }
  display();

}

void board :: moveRight(){
  if(!validMove('d')){//return true do stuff else dont
    cout <<"Can't Move Right" <<endl;
  }
  else{//swap current pos with col--
    cout<< "Moved Right"<<endl;
    ++col;
    int temp = arr[row][col];//take row 2 col 1 
    arr[row][col] = 0;
    arr[row][col-1] = temp;
    
  }
  display();

}

void board :: legalMoves(){
  if(row != 0){//check up //if 0 then dont display 0
    cout << arr[row-1][col] <<endl;
  }
  if(row != 2){//check down
    cout << arr[row+1][col] <<endl;
  }
  if(col != 0){//check left
    cout << arr[row][col-1] <<endl;
  }
  if(col != 2){//check right
    cout << arr[row][col+1] <<endl;
  }
}

board board :: operator = (const board& b){
  for(int i = 0 ; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      this->arr[i][j] = b.arr[i][j];
    }
    
  }
  this->row = b.row;
  this->col = b.col;
  return *this;
}