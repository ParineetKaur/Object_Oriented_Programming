#include <iostream>
using namespace std;

class Fraction{
public:
  Fraction(){
    numerator = 0;
    denominator = 0;
  }

  //mutator to set numerator and denominator
  void setFraction(int num, int denom){
    numerator = num;
    denominator = denom;
  }

  double divide(){
    double divisionVal = ((double)numerator/(double)denominator);
    return divisionVal;
  }

  int getNum(){
    return numerator;
  }

  int getDenom(){
    return denominator;
  }
private:
  int numerator;
  int denominator;
};

int main(){
  Fraction test1;
  cout << "Numerator: " << test1.getNum() << "\nDenominator: " << test1.getDenom() << endl;
  Fraction test2;
  test2.setFraction(40,100);
  cout << "Numerator: " << test2.getNum() << "\nDenominator: " << test2.getDenom() << endl;
  double division = test2.divide();
  cout << test2.getNum() << "/" << test2.getDenom() << " = " << division << endl;
  return 0;
}
