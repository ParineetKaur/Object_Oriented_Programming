#include <iostream>
using namespace std;

const int milesPerGallon = 20;

class Odometer{
public:
  //constructor
  Odometer(){
    milesDriven = 0;
    fuelEfficiency = 0;
  }
  //mutator function to reset
  void reset(){
    milesDriven = 0;
  }
  //mutator function to set fuel efficiency
  void setFE(double fe){
    fuelEfficiency = fe;
  }
  //mutator function to add miles driven to odometer
  void addMiles(double miles){
    milesDriven += miles;
  }
  //accesor function to return number of gallons of gasoline already used
  double getGallons(){
    return milesDriven/milesPerGallon;
  }

  int getMiles(){
    return milesDriven;
  }

  int getFE(){
    return fuelEfficiency;
  }
private:
  int milesDriven;
  int fuelEfficiency;
};

int main(){
  Odometer test1;
  test1.setFE(25);
  cout << "Fuel efficiency: " << test1.getFE() << endl;
  test1.addMiles(40);
  cout << "Miles Driven: " << test1.getMiles() << endl;
  cout << "Gallons of gasoline used: " << test1.getGallons() << endl;
  test1.reset();
  cout << "Miles Driven: " << test1.getMiles() << endl;
  return 0;
}
