//Question 10.2

#include <iostream>
using namespace std;

class Polynomial{
public:
  //Constructors
  Polynomial(){
    coefficients = new double[coeffCount];
    coefficients[0] = 0;
  }
  Polynomial(double c){
    coefficients = new double[coeffCount];
    coefficients[0] = c;
  }
  Polynomial(double arr[], int size){
    coefficients = new double[coeffCount];
    for(int j = 0; j < coeffCount; j++){
      coefficients[0] = arr[j];
    }
  }

  //operator functions
  Polynomial& operator=(const Polynomial& val);
  friend const Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2);
  friend const Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2);
  friend const Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2);

  //cout function
  friend ostream& operator<<(ostream& out, const Polynomial& poly);
  void print() const;

  //setters and getters
  void setCoefficient(double c, int e);
  double getCoefficient(const int& e); //const after

private:
  double* coefficients;
  int coeffCount;
};

Polynomial& Polynomial::operator=(const Polynomial& val){
  if (coeffCount != val.coeffCount){
    delete [] coefficients;
    coeffCount = val.coeffCount;
    coefficients = new double[coeffCount];
  }
  for (int i = 0; i < coeffCount; i++){
    coefficients[i] = val.coefficients[i];
  }

  return *this;
}

const Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2){
  Polynomial difference;
  if (poly1.coeffCount >= poly2.coeffCount){
    difference.coeffCount = poly1.coeffCount;
  }
  else{
    difference.coeffCount = poly2.coeffCount;
  }

  delete [] difference.coefficients;

  difference.coefficients = new double[difference.coeffCount];
  for (int j = 0; j < difference.coeffCount; j++){
    difference.coefficients[j] = 0;
    if (j < poly1.coeffCount){
      difference.coefficients[j] += poly1.coefficients[j];
    }

    if (j < poly2.coeffCount){
      difference.coefficients[j] -= poly2.coefficients[j];
    }
  }

  return difference;
}

const Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2){
  Polynomial product;
  product.coeffCount = poly1.coeffCount + poly2.coeffCount;
  delete [] product.coefficients;
  product.coefficients = new double[product.coeffCount];

  for (int k = 0; k < product.coeffCount; k++){
    product.coefficients[k] = 0;
  }

  for (int i = 0; i < poly1.coeffCount; i++){
    for (int j = 0; j < poly2.coeffCount; j++){
      product.coefficients[i + j] += poly1.coefficients[i] * poly2.coefficients[j];
    }
  }

  return product;
}

const Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2){
  Polynomial sum;
  if (poly1.coeffCount >= poly2.coeffCount){
    sum.coeffCount = poly1.coeffCount;
  }
  else{
    sum.coeffCount = poly2.coeffCount;
  }

  delete [] sum.coefficients;

  sum.coefficients = new double[sum.coeffCount];
  for (int j = 0; j < sum.coeffCount; j++){
    sum.coefficients[j] = 0;
    if (j < poly1.coeffCount){
      sum.coefficients[j] += poly1.coefficients[j];
    }

    if (j < poly2.coeffCount){
      sum.coefficients[j] += poly2.coefficients[j];
    }
  }

  return sum;
}

ostream& operator<<(ostream& out, const Polynomial& poly){
  poly.print();
  return out;
}

void Polynomial::print() const{
  bool nonZero = false;
  for (int i = 0; i < coeffCount; i++){
    if (coefficients[coeffCount - i - 1] != 0){
      nonZero = true;
      cout << coefficients[coeffCount - i - 1];
      if ((coeffCount - i - 1) != 0){
        cout << "x^" << (coeffCount - i - 1);
      }
    }
    else if(nonZero == false){
    cout << "0";
  }
  else{
    cout << "Error..." << endl;
    exit(1);
  }
}
}


int main(){
  //testing constructors
  Polynomial poly1(20);
  Polynomial poly2(10);

  Polynomial poly5 = poly1 + poly2;
  cout << poly5 << endl;
  return 0;
}
