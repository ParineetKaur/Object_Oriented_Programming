//Create a new derived class called Van

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

class Van: public Automobile{
public:
  Van(){
    seats = 7; //default seats
  }

  Van(std::string imake, std::string imodel, int iyear, double iprice, int istall, int seatCount){
    Automobile(imake, imodel, iyear, iprice, istall);
    seats = seatCount;
  }

  bool park(bool lot[], int size){
    int seats = getSeatCount();
    if(seats <= 7){
      return Automobile::park(lot,size);
    }
    else{
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
  }
  int getSeatCount(){
    return seats;
  }
private:
  int seats;
};

int main(){
  Van van1;
  cout << "Van 1: " << endl;
  cout << "Default van: " << endl;
  cout << "Number of Seats: " << van1.getSeatCount() << endl;
  cout << "_______________________________________________" << endl;
  Van van2 ("None Given", "None Given" , 2000, 4000, 0, 6);
  cout << "Van 2: " << endl;
  cout << "Number of seats: " << van1.getSeatCount() << endl;
  cout << "_______________________________________________" << endl;
  Van van3;
  cout << "Where is the van parked?: " << endl;
  bool spot[5] = {false, false, false, false, false};
  bool answer = van3.park(spot, 5);
  if(answer == true){
    bool stallLocation = van3.stall();
    cout << "Parking spot found. Van is parked in stall " << stallLocation << endl;
  }
  else{
    cout << "Parking could not be found. Ending now..." << endl;
    exit(1);
  }
  return 0;
}
