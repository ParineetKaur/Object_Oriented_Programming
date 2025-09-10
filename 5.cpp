//Question 5 of Programming Projects

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class set{
private:
  vector<T> item;
public:
  void add(T i){
    if (find(item.begin(), item.end(), i) == item.end()){//use the find() method to find if item we want to add is present in the array
      item.push_back(i);//add item
      cout << i << " has been added to the set." << endl;
    }
    else{
      cout << "Item was already present, so the program will not add it again." << endl;
    }
  }

  int numberOfItems(){
    int sizeOfSet = item.size();
    return sizeOfSet;
  }

  T* getArray(){
    T* arr = new T[item.size()];
    for(int i = 0; i < item.size(); ++i){
      arr[i] = item[i];
    }
    return arr;
  }
};

int main(){
  char find;
  set<int> set1;
  cout << "Testing with integer type: " << endl;
  set1.add(10);
  set1.add(2);
  set1.add(4);
  set1.add(6);
  set1.add(8);
  int itemCount = set1.numberOfItems();
  cout << "There are " << itemCount << " in the set of items." << endl;
  cout << "Would you like to get a pointer to a dynamically created array? (y/n): ";
  cin >> find;
  if(find == 'y'){
    int* arr = set1.getArray();
    cout << *arr;
    delete arr;
  }
  else{
    cout << "Pointer will not be returned." << endl;
  }
  return 0;
}
