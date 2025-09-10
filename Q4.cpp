//Question 1-3

#include <iostream>
#include <string>
using namespace std;

struct Time{//military time, no am/pm
  int hour;
  int minute;
};

Time earlier(Time t1, Time t2){
  Time ret;
  if(t1.hour == t2.hour){
    if(t1.minute<t2.minute){
      ret = t1;
    }

    else{
      ret = t2;
    }
  }

    else if(t1.hour<t2.hour){
      ret = t1;
    }

    else{
      ret = t2;
    }

    return ret;
  }

class Carpool{
public:
  string names[5]; //string is needed because these are names (so many characters will be used)
  int count;
  Time arrival;
  void print(){
    cout << "These are the people who are carpooling: " <<endl;
    for(int j = 0; j < count; j++){
      cout << names[j] << endl;
    }
    cout << "This carpool arrives at " << arrival.hour <<" hour(s) and " << arrival.minute << " minutes." << endl;
  }
};

Carpool combineCarpool(Carpool car1, Carpool car2); //function declaration

int main(){
  Time t1;
  Time t2;

  t1.hour = 1;
  t1.minute = 30;
  t2.hour = 1;
  t2.minute = 45;

  Carpool car1;
  Carpool car2;
  Carpool car; //within this scope/function, this is the final value(s) we get from the combineCarpool function

   string Car1_Names[] = { "Angeline","Mario"};
   string Car2_Names[] = { "Lily","Sally"};

   car1.count = 2;
   car1.arrival = t1;
   car2.count = 2;
   car2.arrival = t2;

   for (int i = 0; i < 2; i++) {
       car1.names[i] = Car1_Names[i];
   }

   for (int j = 0; j < 2; j++) {
       car2.names[j] = Car2_Names[j];
   }

   car = combineCarpool(car1, car2); //function call
   car.print();
   return 0;
 }

Carpool combineCarpool(Carpool car1, Carpool car2){
  Carpool car3; //to keep the new carpool values in track
   if (car1.count + car2.count <= 5){
     car3.count = 0;
     for (int i = 0; i < car1.count; i++){ //to assign previous car 1 people to car3
       car3.names[car3.count++] = car1.names[i]; //count++ keeps the names in order
     }

     for (int k = 0; k < car2.count; k++){ //to assign previous car 2 people to car3
       car3.names[car3.count++] = car2.names[k]; //count++ keeps the names in order
     }

     car3.arrival = earlier(car1.arrival, car2.arrival); //call to Time function (to calculate new arrival time)
     return car3;
   }

   else{
     car3.count = 0;
     return car3;
   }
 }
