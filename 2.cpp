//Programming Project 17.2

#include <iostream>
using namespace std;

 int size = 0;

class ListNode{
public:
  ListNode(){
    data = 0;
    next = nullptr;
  }
  ListNode(int d, ListNode* n){
    data = d;
    next = n;
  }

  void setNext(ListNode* n){
    next = n;
  }

  int getData(){
    return data;
  }
  ListNode* getNext(){
    return next;
  }
private:
  int data;
  ListNode* next;
};

void insert(ListNode* &list, int pos) {
  ListNode* current = list;
  if (current == NULL) {
    list = new ListNode(pos, NULL);
    return;
  }
  while (current->getNext() != NULL) {
    current = current->getNext();
  }
  current->setNext(new ListNode(pos, NULL));
}


ListNode* mergeLists(ListNode* head1, ListNode* head2){
  ListNode* dummyNode = NULL;
  insert(dummyNode,100);
  ListNode* tail = dummyNode;

  while(head1!=NULL && head2!=NULL){
    if(head1->getData() < head2->getData()){
      tail->setNext(head1);
      head1 = head1->getNext();
    }
    else{
      tail->setNext(head2);
      head2 = head2->getNext();
    }
    tail = tail->getNext();
  }
  tail->setNext(head1 ? head1 : head2);
  return dummyNode->getNext();
}

void print(ListNode* newList){
  while(newList != NULL){
    cout << newList->getData() << " ";
    newList = newList->getNext();
  }
  cout << endl;
}

int main(){
  ListNode* list1 = NULL;
  insert(list1, 1);
  insert(list1, 2);
  insert(list1, 3);
  cout << "List 1: ";
  print(list1);
  ListNode* list2 = NULL;
  insert(list2, 4);
  insert(list2, 5);
  insert(list2, 6);
  cout << "List 2: ";
  print(list2);
  //create new linked list that has the merge merged merged list
  ListNode* list3 = mergeLists(list2,list1);
  cout << "List after merging list 1 and 2: ";
  print(list3);
  return 0;
}
