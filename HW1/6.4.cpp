//Question 6.4 from Programming Lab Homework

#include <iostream>
using namespace std;

class GasPump{
public:
  GasPump();
  GasPump(int amountDispensed, double costPerGallon);
  double getCost();
  void setCost(double cost);
  void startDispense();
  double amountDue();
  int getQuantity();

private:
  int amountCharged;
  double costPerGallon;
  int amountRemaining;
};

GasPump::GasPump(){
  amountCharged = 0;
  costPerGallon = 0.0;
  amountRemaining = 0;
}

GasPump::GasPump(int amountRemaining, double costPerGallon){
  this->costPerGallon = costPerGallon;
  this->amountRemaining = amountRemaining;
}

double GasPump::getCost(){
  return costPerGallon;
}

void GasPump::setCost(double cost){
  costPerGallon = cost;
}

void GasPump::startDispense(){
  amountRemaining--;
  amountCharged += costPerGallon;
}

double GasPump::amountDue(){
  return amountCharged;
}

int GasPump::getQuantity(){
  return amountRemaining;
}

int main(){
  int gallons;
  GasPump gasCalculation(800, 4.50);
  cout << "Current gallons of gas in pump: " << gasCalculation.getQuantity() << endl;
  cout << "Price per gallon of gas: $" << gasCalculation.getCost() << endl;
  cout << "How many gallons of gas would you like to dispense?: " << endl;
  cin >> gallons;

  for(int i = 0; i < gallons; i++){
    gasCalculation.startDispense();
  }
  cout << "Current gallons of gas in pump: " << gasCalculation.getQuantity() << endl;
  cout << "Total cost: $" << gasCalculation.amountDue() << endl;
  cout << "Your Transaction is complete." << endl;
  cout << "___________________________________" << endl;
  GasPump gasCalculation2(0, 4.50);
  cout << "Amount of Gas Dispensed: " << gasCalculation2.getQuantity() << endl;
  cout << "Price per gallon of gas: $" << gasCalculation2.getCost() << endl;
}
