//Programming Project 17.3

#include <iostream>
using namespace std;

struct polyNode{
  int exp;
  int coeff;
  polyNode* link;
};

class Polynomial{
private:
  polyNode* head;
  int power;

  double getCoeff(int exp) const{
    polyNode* temp = head;
       while(temp != NULL){
         if(temp->exp == exp){
           return temp->coeff;
           temp = temp->link;
         }
       }
       return 0;
     }

public:
  //default constructors
  Polynomial(){
    head = NULL;
    power = 0;
  }

  //user-defined constructors (with only one argument)
  Polynomial(int c){
    head = new polyNode;
    head->coeff = c;
    head->exp = 0;
    power = 0;
  }

  //user-defined constructors (with only two argument)
  Polynomial(int c, int p){
    head = new polyNode;
    head->exp = p;
    head->coeff = c;
    power = p;
  }

  //copy constructor
  Polynomial(const Polynomial& other){
    power = other.power;
    head = NULL;
    for(int i = 0; i <=power; i++){
      polyNode* temp = new polyNode;
      temp->coeff = other.getCoeff(i);
      temp->exp = i;
      temp->link = head;
      head = temp;
    }
  }
  //destructor
  ~Polynomial(){
    while(head!=NULL){
      polyNode* temp = head;
      head = head->link;
      delete temp;
    }
  }

  Polynomial multiply(int c, int e) const{
    Polynomial* p = new Polynomial(*this);
    p->power += e;
    polyNode* temp = p->head;
    while(temp!= NULL){
      temp->coeff *= c;
      temp->exp += e;
      temp = temp->link;
    }
    return *p;
  }

  //operator functions
  Polynomial operator+(const Polynomial& poly) const;
  Polynomial operator-(const Polynomial& poly) const;
  Polynomial operator*(const Polynomial& poly) const;

  //output and input
  friend ostream& operator <<(ostream& out, const Polynomial& poly){
    polyNode* temp = poly.head;
    while (temp != NULL){
      if (temp->coeff == 0){
        out << "------------------------" << endl;
      }
      else if (temp->coeff < 0){
        out << "-" << -1 * temp->coeff << "x" << temp->exp << " ";
      }
      else{
        out << temp->coeff << "x" << temp->exp << " ";
      }
      temp = temp->link;
    }
    return out;
   }

   friend istream& operator >>(istream& in, Polynomial& poly){
     int degree;
     poly = Polynomial();
     cout << "Enter the degree of polynomial: ";
     in >> power;
     poly.power = power;
    for (int i = 0; i <= degree; ++i){
      cout << "Enter element#" << i << ": ";
      polyNode* temp = new polyNode;
      in >> temp->coeff;
      temp->exp = i;
      temp->link = poly.head;
      poly.head = temp;
    }
    return in;
  }
};

Polynomial Polynomial::operator+(const Polynomial& poly) const{
  Polynomial  *p = new Polynomial();
  p->power = power > poly.power ? power : poly.power;
  for(int j = 0; j <= p->power; ++j){
    polyNode* temp = new polyNode;
    temp->coeff = getCoeff(j) + poly.getCoeff(j);
    temp->exp = j;
    temp->link = p->head;
    p->head = temp;
  }
  return *p;
}

Polynomial Polynomial::operator-(const Polynomial& poly) const{
  Polynomial *p = new Polynomial();
  p->power = power > poly.power ? power : poly.power;
  for(int j = 0; j <= p->power; ++j){
    polyNode* temp = new polyNode;
    temp->coeff = getCoeff(j) - poly.getCoeff(j);
    temp->exp = j;
    temp->link = p->head;
    p->head = temp;
  }
  return *p;
}

Polynomial Polynomial::operator*(const Polynomial& poly) const{
  Polynomial* temp = head;
  Polynomial* p = new Polynomial();
  while(temp!=NULL){
    *p = (*p) + poly.multiply(temp->coeff,temp->exp);
    temp = temp->link;
  }
  return *p;
}

int main()
{
    Polynomial poly1, poly2;
    char input;
    cin >> poly1;
    cin >> poly2;
    cout << "The first polynomial is: " << poly1 << endl;
    cout << "The second polynomial is: " << poly2 << endl;
    cout << "______________________________________________" << endl;
    cout << "Adding the two polynomials: " << endl;
    cout << "poly1 + poly2 = " << poly1 + poly2 << endl;
    cout << "______________________________________________" << endl;
    cout << "Multiplying the two polynomials: " << endl;
    cout << "poly1 * poly2 = " << poly1 * poly2 << endl;
    cout << "______________________________________________" << endl;
    cout << "Subtracting the two polynomials: " << endl;
    cout << "poly1 - poly2 = " << poly1 - poly2 << endl;

    return 0;
}
