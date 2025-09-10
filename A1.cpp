//Writes Constructors, Getters, and bool function

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

int main(){
  int stall;
  char setStall;
  Automobile car;
  cout << "Printing default car information: " << endl;
  cout << "Car make: " << car.make() << endl;
  cout << "Car model: " << car.model() << endl;
  cout << "Car year: " << car.year() << endl;
  cout << "Car price: " << car.price() << endl;
  cout << "Car is parked in stall: " << car.stall() << endl;
  cout << "_______________________________________________" << endl;
  cout << "Would you like to set the stall number?: " << endl;
  cin >> setStall;
  if(setStall == 'y'){
    cout << "Which stall is the car parked in?: " << endl;
    cin >> stall;
    car.set_stall(stall);
    cout << "Saved...The car is parked in stall number " << car.stall() << endl;
    cout << "Ending now..." << endl;
    exit(1);
  }
  else{
    cout << "Okay, we will find a stall for your car to parked." << endl;
  }
  cout << "_______________________________________________" << endl;
  Automobile car2;
  bool spot[5] = {false, true, false, false, false};
  bool answer = car2.park(spot, 5);
  if(answer == true){
    cout << "Parking spot found. Car is now parked in stall " << car2.stall() << endl;
  }
  else{
    cout << "Parking could not be found. Ending now..." << endl;
    exit(1);
  }
  return 0; 
}
