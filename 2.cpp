//Question 8.2

#include <iostream>
using namespace std;

class Rational{
public:
  Rational(int num, int denom){
    numerator = num;
    denominator = denom;
  }
  Rational(int whole_number){
    numerator = whole_number;
    denominator = 1;
  }
  Rational(){
    numerator = 0;
    denominator = 1;
  }
  friend ostream &operator<<(ostream &out, const Rational &rational_num);
  friend istream &operator>>(istream &in, Rational &rational_num);

  bool operator==(const Rational &n);
  bool operator<(const Rational &n);
  bool operator>(const Rational &n);
  bool operator<=(const Rational &n);
  bool operator>=(const Rational &n);

  Rational operator+(const Rational &n);
  Rational operator-(const Rational &n);
  Rational operator*(const Rational &n);
  Rational operator/(const Rational &n);

  Rational normalize();

private:
  int numerator;
  int denominator;
};

ostream &operator<<(ostream &out, const Rational &rational_num){
  out << rational_num.numerator << "/" << rational_num.denominator;
  return out;
}

istream &operator>>(istream &in, Rational &rational_num){
  char character;
  in >> rational_num.numerator;
  in >> character;
  in >> rational_num.denominator;
  rational_num.normalize();
  return in;
}

bool Rational::operator==(const Rational &n){
  return(numerator==n.numerator && denominator == n.denominator);
}

bool Rational::operator<(const Rational &n){
  return((numerator * n.numerator) < (denominator * n.denominator));
}

bool Rational::operator>(const Rational &n){
  return((numerator * n.numerator) > (denominator * n.denominator));
}

bool Rational::operator<=(const Rational &n){
  return((numerator * n.numerator) <= (denominator * n.denominator));
}

bool Rational::operator>=(const Rational &n){
  return((numerator * n.numerator) >= (denominator * n.denominator));
}

Rational Rational::operator+(const Rational &n){
  int n1 = (numerator * n.denominator) + (denominator * n.numerator);
  int d1 = (denominator * n.denominator);
  Rational newValues(n1,d1);
  return newValues;
}

Rational Rational::operator-(const Rational &n){
  int n1 = (numerator * n.denominator) - (denominator * n.numerator);
  int d1 = (denominator * n.denominator);
  Rational newValues(n1,d1);
  return newValues;
}

Rational Rational::operator*(const Rational &n){
  int n1 = numerator * n.numerator;
  int d1 = denominator * n.denominator;
  Rational newValues(n1,d1);
  return newValues;
}

Rational Rational::operator/(const Rational &n){
  int n1 = (numerator * n.denominator);
  int d1 = (denominator * n.numerator);
  Rational newValues(n1,d1);
  return newValues;
}

Rational Rational::normalize(){
  int n, d, x;
  Rational temp;
  n = numerator;
  d = denominator;
  x = (n*n < d*d)?(x=n):(x=d);
  for (int i=2; i*i<=x*x; i++){
    while ((n%i) == 0 && (d%i) == 0){
      n = n/i;
      d = d/i;
      x = x/i;
    }
  }
  if (d<0){
    temp.numerator = -n;
    temp.denominator = -d;
  }
  else{
    temp.numerator = d;
    temp.denominator = d;
  }
  return temp;
}

int main(){
  Rational val1, val2, newVal;
  cout << "Enter a value: ";
  cin >> val1;
  cout << "Enter another value: ";
  cin >> val2;
  cout << "The first value normalized is " << val1.normalize() << endl;
  cout << "The second value normalized is " << val2.normalize() << endl;

  cout << "Is " << val1 << " = " << val2 << "? " << " --> " << (val1.operator==(val2) ? "yes" : "no") << endl;
  cout << "Is " << val1 << " < " << val2 << "? " << " --> " << (val1.operator<(val2) ? "yes" : "no") << endl;
  cout << "Is " << val1 << " > " << val2 << "? " << " --> " << (val1.operator>=(val2) ? "yes" : "no") << endl;
  cout << "Is " << val1 << " > " << val2 << "? " << " --> " << (val1.operator<=(val2) ? "yes" : "no") << endl;

  newVal = val1.operator+(val2);
  cout << "Addition: " << newVal << endl;
  cout << "Normalized sum value: " << newVal.normalize() << endl;

  newVal = val1.operator-(val2);
  cout << "Subtraction: " << newVal << endl;
  cout << "Normalized value that was substracted: " << newVal.normalize() << endl;

  newVal = val1.operator*(val2);
  cout << "Multiplication: " << newVal << endl;
  cout << "Normalized product value: " << newVal.normalize() << endl;

  newVal = val1.operator/(val2);
  cout << "Division: " << newVal << endl;
  cout << "Normalized quotient value: " << newVal.normalize() << endl;

  return 0;
}
