//Create a new derived class called Pickup

#include <iostream>
using namespace std;

//base class
class Automobile{
public:
  //constructors
    Automobile() : make_("None"), model_("None"), year_(0000), price_(0), stall_(0){}
    Automobile(std::string imake, std::string imodel, int iyear, double iprice, int istall){
      make_ = imake;
      model_ = imodel;
      year_ = iyear;
      price_ = iprice;
      stall_ = istall;
    }
    //find an empty spot in lot
    bool park(bool lot[], int size){
      int newSpot;
      bool found = false;
      for(int i=0; i < size; i++){
        if(lot[i] == true){
          newSpot = i;
          found = true;
          break;
        }
      }

      if(found == true){
        stall_ = newSpot;
        return true;
      }
      else{
        return false;
      }
    }
    //getters and setters
    string make(){return make_;}
    string model(){return model_;}
    int year(){return year_;}
    double price(){return price_;}
    int stall(){return stall_;}
    void set_stall(int s){stall_ = s;}
private:
    std::string make_;
    std::string model_;
    int year_;
    double price_;
    int stall_;
};

class Pickup:public Automobile{
public:
  Pickup(){
    capacity = 0;
    extendedCab = false;
  }

  Pickup(std::string imake, std::string imodel, int iyear, double iprice, int istall, int c, int e){
    Automobile(imake, imodel, iyear, iprice, istall);
    capacity = c;
    extendedCab = e;
  }

  int getCapacity(){
    return capacity;
  }

  int getExtended(){
    return extendedCab;
  }

  bool park(bool lot[], int size){
    int newSpot;
    bool found = false;
    for(int i=0; i < size; i++){
      if(lot[i] == true){
        newSpot = i;
        found = true;
        break;
      }
    }

    if(found == true){
      if(newSpot + 1 < size){
        lot[newSpot] = true;
        lot[newSpot + 1] = true;
        set_stall(newSpot);
      }
      return true;
    }
    else{
      return false;
    }
  }
private:
  int capacity;
  bool extendedCab;
};

int main(){
  bool extended;
  Pickup pick1;
  cout << "Pickup 1: " << endl;
  cout << "Default pickup: " << endl;
  cout << "Capacity: " << pick1.getCapacity() << endl;
  cout << "Is it an extended cab?: " << endl;
  extended = pick1.getExtended();
  if(extended == false){
    cout << "This is not an extended cab." << endl;
  }
  else if(extended == true){
    cout << "This is an extended cab." << endl;
  }
  else{
    cout << "Illegal option. Ending now..." << endl;
    exit(1);
  }
  cout << "_______________________________________________" << endl;
  Pickup pick2("Volkwagen", "Hatchback Beetle", 2019, 40000, 8, 4, false);
  Automobile car2("Volkwagen", "Hatchback Beetle", 2019, 40000, 8);
  cout << "Pickup 2: " << endl;
  cout << "Default pickup: " << endl;
  cout << "Cab make: " << car2.make() << endl;
  cout << "Cab Make: " << car2.model() << endl;
  cout << "Cab year: " << car2.year() << endl;
  cout << "Car total price: " << car2.price() << endl;
  cout << "Capacity: " << pick2.getCapacity() << endl;
  cout << "Is it an extended cab?: " << endl;
  extended = pick2.getExtended();
  if(extended == false){
    cout << "This is not an extended cab." << endl;
  }
  else if(extended == true){
    cout << "This is an extended cab." << endl;
  }
  else{
    cout << "Illegal option. Ending now..." << endl;
    exit(1);
  }
  cout << "Car stall location: " << endl;
  int stallLocation = car2.stall();
  cout << "Stall 1: " << stallLocation << endl;
  cout << "Adjacent stall: " << stallLocation + 1 << endl;
  cout << "_______________________________________________" << endl;
  Pickup pick3;
  bool spot[5] = {false, false, false, true, false};
  bool answer = pick3.park(spot, 5);
  if(answer == true){
    stallLocation = pick3.stall();
    cout << "Parking spot found. Car is now parked in stalls " << stallLocation << " and " << stallLocation + 1 << endl;
  }
  else{
    cout << "Parking could not be found. Ending now..." << endl;
    exit(1);
  }
  return 0;
}
