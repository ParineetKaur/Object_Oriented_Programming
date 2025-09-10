//Programming Project 17.5

#include <iostream>
using namespace std;

class SuitorNode{
public:
  SuitorNode(){
    next = NULL;
    num = 0;
  }
  ~SuitorNode(){
  }
  SuitorNode(int suitorNum){
    num = suitorNum;
    next = NULL;
  }
  SuitorNode* getNext(){
    return next;
  }
  int getNum(){
    return num;
  }
  void setNext(SuitorNode* nextNode){
    next = nextNode;
  }
private:
  SuitorNode* next;
  int num;
};

int main(){
  int numSuitors;
  SuitorNode* current = NULL;
  SuitorNode* tail = NULL;
  SuitorNode* prev = NULL;
  cout << "Enter number of suitors: " << endl;
  cin >>numSuitors;
  if(numSuitors<=0){
    cout << "Not enough suitors!" << endl;
  }
  else if(numSuitors == 1){
    cout << "You would stand first in line." << endl;
  }
  else{
    //create circular linked list
    current = new SuitorNode(1);
    current->setNext(current); //circular list
    tail = current; //"end" of the list
    for(int i = 2; i <= numSuitors; i++){
      SuitorNode* temp = new SuitorNode(i);
      temp->setNext(tail->getNext());
      tail->setNext(temp);
      tail = temp;
    }
    while(current->getNext() != current){
      //count three people ahead by traversing two links
      for(int i = 0; i < 2; i++){
        prev = current;
        current = current->getNext();
      }
      //delete the node pointed to by current
      prev->setNext(current->getNext());
      delete current;
      current = prev->getNext();
    }
    cout << "To marry the princess you should stand in position " << endl;
    cout << current->getNum() << endl;
    delete current;
  }
  cout << "Enter a character to exit." << endl;
  char wait;
  cin >> wait;
  return 0;
}
