#include <iostream>
using namespace std;

class Node{
public:
  int Val;
  Node* next;
};

void printList(Node* n){
  while(n!=NULL){
    cout << n->Val << endl;
    n = n->next;//go to the next node
  }
}

//inserting a node or element after another node
void insertAfter(Node* previous, int newVal){
   //1) Check if previous node is NULL or not
   if(previous == NULL){
     cout << "The previous node can NOT be NULL." << endl;
     return;
   }
   //2) Prepare a new node
   Node* newNode = new Node();
   newNode->Val = newVal;
   //3) Insert this new node after the previous node
   newNode->next = previous->next;
   previous->next = newNode;
}

int main(){
  //list will have three elements (aka node)
  Node* head = new Node();
  Node* second = new Node();
  Node* third = new Node();

  //assigning elements and linking think
  head->Val = 1; //assign head
  head->next = second; //link to second
  second->Val = 2;
  second->next = third; //link to third
  third->Val = 3;
  third->next = NULL;

  //link elements
  head->next = second;

  //print list
  printList(head);

  //inserting a node or element after another node
  insertAfter(head,4); //
  cout << "After inserting 4 after head: " << endl;
  printList(head);
  return 0;
}
