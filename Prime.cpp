#include <iostream>
using namespace std;
class PrimeNumber{
private:
  int num;
  bool isPrime(int num);
public:
  PrimeNumber();
  PrimeNumber(int prime);
  int get();
  const PrimeNumber operator ++(int);
  const PrimeNumber operator --(int);
};

PrimeNumber::PrimeNumber() : num(1){}

PrimeNumber::PrimeNumber(int prime){
  num = prime;
}

//accessor
int PrimeNumber::get(){
  return num;
}

bool PrimeNumber::isPrime(int num){
  for(int i = num - 1; i > 1; i--){
    if((num % i) == 0){
      return false;
    }
  }
  return true;
}

const PrimeNumber PrimeNumber::operator ++(int){
  int nextprime = num;
  do{
    nextprime++;
  }while(!isPrime(nextprime));
  return PrimeNumber(nextprime);
}

const PrimeNumber PrimeNumber::operator --(int){
  int previousprime = num;
  do{
    previousprime--;
    if(previousprime < 1){
      return PrimeNumber(1);
    }
  }while(!isPrime(previousprime));
  return PrimeNumber(previousprime);
}

int main(){
  PrimeNumber p1, p2(13);
  cout << p1.get() << endl;
  cout << p2.get() << endl;

  PrimeNumber p3 = p1++;
  cout << p3.get() << endl;

  PrimeNumber p4 = p2++;
  cout << p4.get() << endl;

  PrimeNumber p5 = p2--;
  cout << p5.get() << endl;

  PrimeNumber p6 = p1--;
  cout << p6.get() << endl;
  return 0;
}
