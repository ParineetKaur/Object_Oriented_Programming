//Question 7.3

#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

class Counter{
public:
  Counter(int m);

  void incr1(int n);
  void incr10(int n);
  void incr100(int n);
  void incr1000(int n);

  bool overflow();
  bool over_flow;
  void reset(); //reset to 0
  void setLimit(int n);
  int getCounter();
  int getLimit();

private:
  int number;
  int max;
};

Counter::Counter(int m){
  number = 0;
  if(m > 0 && m<= 9999){
    max = m;
  }
  else{
    cout << "This is not a valid value. The counter is going to be set to 9999 by default."<<endl;
    max = 9999;
  }
  over_flow = false;
}

void Counter::incr1(int n){
  if(number + n >= max){
    over_flow = true;
  }
  else{
    number = number + 1;
  }
}

void Counter::incr10(int n){
  if(number + 10 * n >= max){
    over_flow = true;
  }
  else{
    number = number + 10 * n;
  }
}

void Counter::incr100(int n){
  if(number + 100 * n >= max){
    over_flow = true;
  }
  else{
    number = number + 100 * n;
  }
}


void Counter::incr1000(int n){
  if (number + 1000 * n >= max){
    over_flow = true;
  }
  else{
    number = number + 1000 * n;
  }
}


bool Counter::overflow(){
  return over_flow;
}

void Counter::reset(){
  over_flow = false;
  number = 0;
}

void Counter::setLimit(int n){
  reset();
  if (n > 0 && n <= 9999){
    max = n;
   }
   else{
     cout << "This is not a valid value. The counter is going to be set to 9999 by default." << endl;
     max = 9999;
  }
}

int Counter::getCounter(){
  return number;
}

int Counter::getLimit(){
  return max;
}

bool checkKey(char key){
  if (key == 'a'){
    return true;
  }
  if (key == 'i'){
    return true;
  }
  if (key == 's'){
    return true;
  }
  if (key == 'd'){
    return true;
  }
  if (key == 'f'){
    return true;
  }
  if (key == 'o'){
    return true;
  }
  if (key == 'r'){
    return true;
  }
  if (key == 'q'){
    return true;
  }


   cout << "key = " << key << endl;
   return false;
}

int main(){
  char key;
  int m = 0;
  cout << "Enter a limit between 0-9999 for the counter: ";
  cin >> m;
  Counter counter1(m);
  cout << "Counter Value: " << counter1.getCounter() << " , Counter Limit: " << counter1.getLimit() << endl;

  cout << "What would you like to do with this counter?: " << endl;
  cout << "Press a to enter cents " << endl;
  cout << "Press s to enter dimes " << endl;
  cout << "Press d to enter dollars " << endl;
  cout << "Press f to enter tens of dollars " << endl;
  cout << "Press r to reset counter " << endl;
  cout << "Press c to set counter " << endl;
  cin >> key;

  while(checkKey(key)){
    if(key=='a'){
      int increment;
      cout << "Enter(1 - 9) to increment: ";
      cin >> increment;
      counter1.incr1(increment);
      if (counter1.overflow()){
        counter1.reset();
        cout << "You've exceeded counter limit, which was " << counter1.getLimit() << endl;
        cout << "The counter is now being reset to 0." << endl;
      }
    }

    else if (key == 's'){
      int increment;
      cout << "Enter(1 - 9) to increment : ";
      cin >> increment;
      counter1.incr10(increment);
      if (counter1.overflow()){
        counter1.reset();
        cout << "You've exceeded counter limit, which was " << counter1.getLimit() << endl;
        cout << "The counter is now being reset to 0." << endl;
      }
    }

    else if(key == 'd'){
      int increment;
      cout << "Enter(1 - 9) to increment : ";
      cin >> increment;
      counter1.incr100(increment);
      if (counter1.overflow()){
        counter1.reset();
        cout << "You've exceeded counter limit, which was " << counter1.getLimit() << endl;
        cout << "The counter is now being reset to 0." << endl;
      }
    }

    else if(key == 'f'){
      int increment;
      cout << "Enter(1 - 9) to increment : ";
      cin >> increment;
      counter1.incr1000(increment);
      if (counter1.overflow()){
        counter1.reset();
        cout << "You've exceeded counter limit, which was " << counter1.getLimit() << endl;
        cout << "The counter is now being reset to 0." << endl;
      }
    }

    else if(key == 'r'){
      counter1.reset();
    }

    else if (key == 'c'){
      cout << "Enter a limit between 0-9999 for the counter: ";
      int l;
      cin >> l;
      counter1.setLimit(l);
    }

    cout << "Counter Value: " << counter1.getCounter() << " , Counter Limit: " << counter1.getLimit() << endl;

    cout << "What would you like to do with this counter?: " << endl;
    cout << "Press a to enter cents " << endl;
    cout << "Press s to enter dimes " << endl;
    cout << "Press d to enter dollars " << endl;
    cout << "Press f to enter tens of dollars " << endl;
    cout << "Press r to reset counter " << endl;
    cout << "Press c to set counter " << endl;
    cout << "Press q to stop " << endl;
    cin >> key;
    if(key=='q'){
      exit(1);
    }
}
return 0;
}
