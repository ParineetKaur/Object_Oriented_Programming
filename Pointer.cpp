#include <iostream>
using namespace std;

int main(){
  int size;
  int x = 9;
  int y = 10;
  int A[2] = {10, 20};
  int* ptr1;
  ptr1 = &x; //pointing to address of x
  cout << ptr1 << " --> This will output an address of the variable the pointer is pointing to" << endl;
  cout << *ptr1 << " --> This will output the value stored inside of teh variable (this called dereferencing)" << endl;

  cout << "___________________________________________________________________" << endl;
  cout << A << " --> This will output the address of the first element of the array" << endl;
  cout << &A[0] << " --> This will output the address of the first element of the array. The above should be the same as this address!!" << endl;
  cout << A[1] << endl;
  cout << "___________________________________________________________________" << endl;
  cout << "What we have been doing to get size if we do not know it?" << endl;
  cout << "We asked the user: What size would you want the array to be: " << endl;
  cin >> size;
  //int arr[size];
  cout << "We can do this differently: USE DYNAMIC ARRAYS" << endl;
  cout << "Use new to allocate memory and delete to deallocate the memory" << endl;
  int* arr = new int [size]; //allocated an array of this size the user specifies
  for(int i = 0; i < size; i++){
    cout << "Array[" << i << "] ";
    cin >> arr[i];
  }
  for(int i = 0; i < size; i++){
    //cout << arr[i] << " , ";
    cout << *(arr+i) << " " << endl; //another way to dereferencing the array
  }
  cout << "Deallocate memory..." << endl;
  delete [] arr;
  arr = NULL; //this is going to assign 0 to the array. We do this to prevent accidental crashes to array. Now, the array is not pointing to anything!
  cout << "Process completed" << endl;
  cout << "___________________________________________________________________" << endl;
  cout << "Multidimensional Dynamic Array" << endl;
  int rows, cols;
  cout << "Enter rows and columns in table: "  << endl;
  cin >> rows >> cols;
  int** table = new int*[rows]; //creating an integer array of pointers
  for(int j = 0; j < rows; j++){
    table[j] = new int[cols];
  }
  table[1][2] = 88;
  cout << "Deallocate backwards..." << endl;
  for(int j = 0; j < rows; j++){
    delete [] table[j];
  }
  delete [] table;
  table = NULL;
  cout << "Process completed" << endl;
  return 0;
}
