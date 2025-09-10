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

//inserting a node or element at the end of the linked list
void insertAtBack(Node**head, int newVal){
   //1) Prepare a new node
   Node* newNode = new Node();
   newNode->Val = newVal;
   newNode->next = NULL; //because this is the last node of the list, then it will not point to any other element/node
   //2) Check: If linked list is empty, then the new node we create will be the head
   if(*head == NULL){
     *head = newNode;
     return;
   }
   //3) Find the last node
   Node* last = *head; //use this to traverse the list
   while(last->next != NULL){
     last = last->next;
   }
   //4) Insert new node after the current last node (at the end)
   last->next = newNode;
}
\
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

  //inserting a node or element at the back of the linked list
  insertAtBack(&head,4); //pass address of head and value that you want to add
  cout << "After inserting 4 at back: " << endl;
  printList(head);
  return 0;
}
