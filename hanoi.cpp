//Tower of Hanoi problem

#include <iostream>
using namespace std;

void towerOfHanoi(int start, int end, char source, char helper, char destination){//start means the firsr disk and end is last dism
  if(start > end){
    return;
  }
  towerOfHanoi(start,end-1,source,destination,helper);
  cout << "Move disk from " << source << " to " << destination << endl;
  towerOfHanoi(start,end-1,helper,source,destination);
}

int main(){
  towerOfHanoi(1,2,'A','B','C');
  return 0;
}
