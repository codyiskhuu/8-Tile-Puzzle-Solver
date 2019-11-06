#ifndef __TREE_H__
#define __TREE_H__
#include "board.h"
#include <list>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm> 
using namespace std;

class tree{
  private:
  
  //board* curr;
  
  vector <board*> problems;//holds all nodes to traverse it

  public:
  board* root;  
  board* curr;
  board* prevNode;
  // board* goals;
  
  tree();
  void goUp();
  void goDown();
  void goLeft();
  void goRight();
  void displayBoard();//display root first
  void displayBoard(board* cur);//recursively display the paths taken // probably need to change on heuristic
  void getDistance();//shows the moves//calculates the distance of the goal
  // vector<board*> expand(board*);
  bool expand(board* , vector<board*> &, int);
  void createBoard();


  string leafHash;
  map<string, bool> *blacklist = new map<string,bool>;



  void generalSearch(board* cur ,int heuristic){
    // int curScores = heuristic + cur->score;
    problems.push_back(cur);//make queue and push the intial state
    //problems hold all the boards
    board* lowestNode = NULL;
    board* tempNode;
    vector<board*> tempVector;
    unsigned int lowestScore = 100000;
    int lowestLocation =0;

   // int k =0;
    while(true){
      
      if( problems.empty() ){//go through entire list nodes// then get the one with best score// then expand that nodee by putting those children into the list of problems // then check any of them are the solution//otherwise keep looping 
        cout<<"fail"<<endl;
        return;
      }
      
      for(int i = 0; i < problems.size(); ++i){
        tempNode = problems.at(i);//get the root/traverse through all nodes
        // leafHash = tempNode->getHash();
        //get heuristic: at this moment heuristic is constant
        tempNode->addScore(heuristic, tempNode->depth);//get the score
          
        if(lowestNode == NULL){//root
          cout<<"lowest Node assigned"<<endl;
          lowestNode = tempNode;//node with the lowest score 
          lowestLocation = 0;
        }//right now lowest score isnt changing
        else if( lowestNode->score > tempNode->score){//get smallest score
          cout<<"new lowest Location and Node" <<endl;
          lowestLocation = i;
          lowestNode = tempNode;//inside should be lowest . score
        }
      }
      

      //FUNCTION
      //expanding lowest Node
      // all possible operators
      // left up right down and add that to the children of the lowestnode and add it to the list of problems
      //and put lowestNode in blacklist


      cout<<"expanding lowest Node at Location: " << lowestLocation <<endl;
      lowestNode->display();//show lowest scoring board
      string lowHash = lowestNode->getHash();//get the has of this
      
      cout<<"Mapping this Hash: " <<lowHash<<endl;//show the hash
      
      blacklist->insert( pair<string,bool>(lowHash , true) );//map the lowest hash      
      cout<<"blacklist size: "<<blacklist->size()<<endl;//show hot big the hash is
      
      if(blacklist->find(lowHash) != blacklist->end()){
        cout<<endl<<endl <<"Black List is accepted"<<endl<<endl;
      }

      if(expand(lowestNode, problems, heuristic)){// I EXPAND HERE// if a move is on the map, do not store it
        cout<<"done"<<endl;
        return;
      }//expanding and it get up left then right

      cout<<"vector has been pushed back with: " <<problems.size() <<" items: at: "<<lowestLocation <<endl;

      for(int i =0; i<problems.size();++i){
        problems.at(i)->display();
      }      

      problems.erase( problems.begin()+lowestLocation );//erase the problem
      lowestNode = problems.at(0);//set new problem
      lowestLocation = 0;//reset location of lowest node
      curr = lowestNode;//make it current?

      cout<<"blacklist size: "<<blacklist->size()<<endl;

      cout<<"vector has this : " <<problems.size() <<" items after erase"<<endl;
      for(int i =0; i<problems.size();++i){
        problems.at(i)->display();
      }
      

    }


  }
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