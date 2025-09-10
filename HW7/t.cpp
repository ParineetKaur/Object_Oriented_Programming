#include <string>
#include <iostream>
#include <cmath>

using namespace std;


struct node{
   int exp;
   double coeff;
   node *next;
};

class Polynomial{
private:
   node *head;
   int degree;

   double getCoefficient(int exp) const {
       node *temp = head;
       while (temp != NULL){
           if (temp->exp == exp)
               return temp->coeff;
           temp = temp->next;
       }
       return 0;
   }

public:
   Polynomial(){
       head = NULL;
       degree = 0;
   }

   Polynomial(const Polynomial &p){
       degree = p.degree;
       head = NULL;
       for (int i = 0; i <= degree; ++i){
           node *temp = new node;
           temp->coeff = p.getCoefficient(i);
           temp->exp = i;
           temp->next = head;
           head = temp;
       }
   }

   Polynomial(double c){
       head = new node;
       head->coeff = c;
       head->exp = 0;
       degree = 0;
   }

   Polynomial(double c, int e){
       head = new node;
       head->coeff = c;
       head->exp = e;
       degree = e;
   }

   friend ostream &operator <<(ostream &out, const Polynomial &p){
       node *temp = p.head;
       while (temp != NULL){
           if (temp->coeff == 0){
               // do not print
           }
           else if (temp->coeff < 0){
               out << "-" << -1 * temp->coeff << "x" << temp->exp << " ";
           }
           else{
               out << "+" << temp->coeff << "x" << temp->exp << " ";
           }
           temp = temp->next;
       }
       out << endl;
       return out;
   }

   friend istream &operator >>(istream &in, Polynomial &p){
       int degree;
       p = Polynomial();
       cout << "Enter the degree of polynomial: ";
       in >> degree;
       p.degree = degree;
       for (int i = 0; i <= degree; ++i){
           cout << "Enter a" << i << ": ";
           node *temp = new node;
           in >> temp->coeff;
           temp->exp = i;
           temp->next = p.head;
           p.head = temp;
       }
       return in;
   }

   const Polynomial operator+(const Polynomial &p) const{
       Polynomial *np = new Polynomial();
       np->degree = degree > p.degree ? degree : p.degree;
       for (int i = 0; i <= np->degree; ++i){
           node *temp = new node;
           temp->coeff = getCoefficient(i) + p.getCoefficient(i);
           temp->exp = i;
           temp->next = np->head;
           np->head = temp;
       }
       return *np;
   }

   const Polynomial operator-(const Polynomial &p) const{
       Polynomial *np = new Polynomial();
       np->degree = degree > p.degree ? degree : p.degree;
       for (int i = 0; i <= np->degree; ++i){
           node *temp = new node;
           temp->coeff = getCoefficient(i) - p.getCoefficient(i);
           temp->exp = i;
           temp->next = np->head;
           np->head = temp;
       }
       return *np;
   }

    Polynomial multiplyWithSingleTerm(double c, int e) const{
       Polynomial *p = new Polynomial(*this);
       p->degree += e;
       node *temp = p->head;
       while (temp != NULL){
           temp->coeff *= c;
           temp->exp += e;
           temp = temp->next;
       }
       return *p;
   }

   const Polynomial operator*(const Polynomial &p) const{
       node *temp = head;
       Polynomial *np = new Polynomial();
       while (temp != NULL){
           *np = (*np) + p.multiplyWithSingleTerm(temp->coeff, temp->exp);
           temp = temp->next;
       }
       return *np;
   }


};

int main(){
   Polynomial p1, p2;
   cin >> p1;
   cin >> p2;
   cout << "p1 = " << p1 << endl;
   cout << "p2 = " << p2 << endl;
   cout << "p1 + p2 = " << p1 + p2 << endl;
   cout << "p1 - p2 = " << p1 - p2 << endl;
   cout << "p1 * p2 = " << p1 * p2 << endl;
   return 0;
}
