#include <iostream>
using namespace std;

class Stat{
public:
  int FindMax(); //getter
  void Input(int A[], int size); //setter
private:
  int B[10];
  int size;
};

void Stat::Input(int A[], int arrSize){
  for(int j = 0; j < arrSize; j++){
    A[j] = 123 + j;
  }
  for(int i = 0; i < arrSize; i++){
    B[i] = A[i];
  }
  size = arrSize;
}

int Stat::FindMax(){
  int max = B[0];
  for(int i = 0; i < size; i++){
    if(B[i] > max){
      max = B[i];
    }
  }
  return max;
}

int main(){
  int size = 10;
  int A[size];
  Stat stat1;
  stat1.Input(A,size);
  int max = stat1.FindMax();
  cout << "The max is " << max << endl;
  return 0;
}
