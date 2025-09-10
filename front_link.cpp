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

//inserting a node or element in the front of the linked list
void insertAtFront(Node**head, int newVal){
  //1) Prepare a new node
  Node* newNode = new Node();
  newNode->Val = newVal;
  //2) Put the new node in front of the current head
  newNode->next = *head;
  //3) Move head of the linked list to point to new node
  *head = newNode;
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

  //print list
  printList(head);

  //inserting a node or element in the front of the linked list
  insertAtFront(&head,0); //pass address of head and value that you want to add
  cout << "After inserting 0 at front: " << endl;
  printList(head);
  return 0;
}
