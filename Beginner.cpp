#include <iostream>
using namespace std;

int FindMax(int A[], int size){
  int max = A[0];
  for(int i = 0; i < size; i++){
    if(A[i] > max){
      max = A[i];
    }
  }
  return max;
}

int FindAverage(int A[], int size){
  int sum = 0;
  int average = 0;
  for(int i = 0; i< size; i++){
    sum += A[i];
  }
  average = sum/size;
  return average;
}

int main(){
  int max;
  int average;
  int A[6] = {10, 20, 40, 34, 89, 24};
  max = FindMax(A,6);
  average = FindAverage(A,6);
  cout << "Max: " << max << endl;
  cout << "Average: " << average << endl;
  return 0;
}
