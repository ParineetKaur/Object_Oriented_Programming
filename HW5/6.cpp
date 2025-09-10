//Question 6 of Programming Projects

#include <iostream>
#include <string>
using namespace std;

template <class T> class DynamicStringArray{
private:
  T* dynamicArray;
  int size;
public:
  DynamicStringArray(){
    dynamicArray = nullptr;
    size = 0;
  }

  int getSize(){
    return size;
  }

  void addEntry(string newElement);
  bool deleteEntry(string input);
  string getEntry(int index);
  DynamicStringArray(const DynamicStringArray& other);
  void operator=(const DynamicStringArray& other);
  ~DynamicStringArray();
};

template<class T>void DynamicStringArray<T>::addEntry(string newElement){
  string* newDynamicArray = new T[size+1];
  for(int i = 0; i < size; i++){
    if(i == size - 1){
      newDynamicArray[i] = newElement;
    }
    else{
      newDynamicArray[i] = dynamicArray[i];
    }
  }
  size++;
  delete [] dynamicArray;
  dynamicArray = newDynamicArray;
}

template<class T>bool DynamicStringArray<T>::deleteEntry(string input){
  int l = 0;
  for(int i = 0;i<size;i++){
    if(dynamicArray[i] == input){
      string * newArray = new string[--size];
      for(int j = 0; j < size + 1; j++){
        if(j!=i){
          newArray[l] = dynamicArray[j];
          l++;
        }
      }
      delete [] dynamicArray;
      dynamicArray = newArray;
      return true;
    }
  }
  return false;
}

template<class T>string DynamicStringArray<T>::getEntry(int index){
  if(index > size + 1){
    string notFound = "false";
    return notFound;
  }
  for(int i = 0; i < size; i++){
    if(i == index){
      return dynamicArray[i];
    }
  }
}

template<class T>DynamicStringArray<T>::DynamicStringArray(const DynamicStringArray& other){
  dynamicArray = other.dynamicArray;
  size = other.size;
}

template<class T>void DynamicStringArray<T>::operator=(const DynamicStringArray& other){
  dynamicArray = other.dynamicArray;
  size = other.size;
}

template<class T>DynamicStringArray<T>::~DynamicStringArray(){
  delete [] dynamicArray;
  dynamicArray = nullptr;
}

int main(){
  DynamicStringArray<string>arr1;
  arr1.addEntry("Parneet");
  arr1.addEntry("is");
  arr1.addEntry("a");
  arr1.addEntry("student.");
  cout << "Size of the dynamic array: " << arr1.getSize() << endl;
  cout << "Getting items in list: " << endl;
  cout << "Deleting entry 'student'.... " << endl;
  bool deleted = arr1.deleteEntry("student.");
  if (deleted == true){
    cout << "This item has been deleted." << endl;
  }
  else{
    cout << "This item was not found, so nothing was deleted." << endl;
  }
  return 0;
}
