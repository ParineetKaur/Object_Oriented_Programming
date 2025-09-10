//Question 6.2 from Programming Lab Homework

#include <iostream>
using namespace std;

class CounterType{
public:
  CounterType(){//contructor to initialize the counter = 0
    counter = 0;
  }

  void setCounter(int counter); //mutator function
  void IncCounter(); //member function
  void DecCounter(); //member function
  int getCounter(); //accessor function
private:
  int counter;
};

void CounterType::setCounter(int counter){
  if(counter > 0){
    this->counter = counter; //using a pointer for the system
  }
  else{
    cout << "This is a negative integer value. Provide a nonnegative value.";
  }
}

void CounterType::IncCounter(){
  counter = counter + 1;
}

void CounterType::DecCounter(){
  counter = counter - 1;
}
int CounterType::getCounter(){
  return counter;
}

int main(){ //test program
  CounterType Counter_1;
  Counter_1.setCounter(10);
  cout << "The orginal counter value is: " << Counter_1.getCounter() << endl;
  cout << endl;
  Counter_1.IncCounter();
  cout << "The incremented counter value is: " << Counter_1.getCounter() << endl;
  cout << endl;
  Counter_1.DecCounter();
  cout << "The decremented counter value is: " << Counter_1.getCounter() << endl;
  cout << endl;
}
