#include <iostream>
using namespace std;

const int SMALL = 1;
const int MEDIUM = 2;
const int LARGE = 3;

const int DEEPDISH = 1;
const int HANDTOSSED = 2;
const int PAN = 3;

Class Pizza{
private:
  int type;
  int size;
  bool extraCheese;
  bool mushrooms;
public:
  //constructor
  Pizza(){
    type = deepdish;
    size = small;
    extraCheese = false;
    mushrooms = false;
  }
  //getters
  int getType(){
    return type;
  }

  int getSize(){
    return size;
  }

  int getCheese(){
    return cheese;
  }

  int getMushrooms(){
    return mushrooms;
  }

  //setters
  void setType(int PizzaType){
    type = PizzaType;
  }

  void setSize(int PizzaSize){
    size = PizzaSize;
  }

  void setCheese(bool cheeseChoice){
    extraCheese = cheeseChoice;
  }

  void setMushrooms(bool mushroomChoice){
    mushrooms = mushroomChoice;
  }

  void outputDescription();

  double computePrice();
};

void Pizza::outputDescription(){
  switch(size){
    case SMALL :
    cout << "Small";
    break;

    case MEDIUM:
    cout << "Medium";
    break;

    case LARGE:
    cout << "Large";
    break;

    default:
    cout << "Unkown size";
    break;
  }

  switch(type){
    case DEEPDISH:
    cout << "deepdish";
    break;

    case HANDTOSSED:
    cout << "handtossed";
    break;

    case PAN:
    cout << "pan";
    break;

    default:
    cout << "Unkown type";
    break;
  }

  cuot << pizza;
}

double computePrice(){
  double cost;
  //use switch case to find the same
  //use if/else statement to add topping cost as well
  //return cost
}
