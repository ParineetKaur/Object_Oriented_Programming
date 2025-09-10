//Question 1 of Programming Projects

#include <iostream>
using namespace std;

template <typename T>
int binarySearch(T arr[], T size){
  int l = 0, r = size - 1;
  while (l <= r){
    int m = l + (r - l) / 2;
    if (arr[m] == size){
      return m;
    }
    else if (arr[m] < size){
      l = m + 1;
    }
    else{
      r = m - 1;
    }
  }
  return -1;
}

int main(){
  int a[] = {2,4,6,8,10,12,14,16,18,20};
  cout << binarySearch<int>(a,10) << endl;
  return 0;
}
