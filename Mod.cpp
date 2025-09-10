#include <iostream>
using namespace std;

class ModInt{
public:
  ModInt(){ //Constructor #1 for us to initialize values of mod and val
    mod = 0;
    val = 0;
  }

  ModInt(int modular, int value){ //Constructor #2 to tell the program what operation to perform
    mod = modular;
    val = value % mod;
  }

  int getModValue(){
    return mod;
  }

  int getValValue(){
    return val;
  }

   friend bool operator ==(ModInt lhs, ModInt rhs); //we must use the friend function for this because this is a non-member function, but it has access to the mod and val private variables

   void operator +=(ModInt rhs); //member function

   friend ModInt operator +(ModInt lhs, ModInt rhs); //we must use the friend function for this because this is a non-member function, but it has access to the mod and val private variables


private:
  int mod;
  int val;
};


bool operator ==(ModInt lhs, ModInt rhs){
  if(lhs.val % lhs.mod == rhs.val % rhs.mod){
    return 1; //return this for if this is true
  }
  else{
    return 0; //return this for if this is false
  }
}

void ModInt::operator +=(ModInt rhs){
  if(mod == rhs.mod){ //condition for the execution of this function
    val += rhs.val;
    val %= rhs.mod;
  }
  else{
    mod = -1;
    val = -1;
  }
}

ModInt operator +(ModInt lhs, ModInt rhs){
  ModInt modAdd;
  if(lhs.mod == rhs.mod){ //condition for the execution of this function
    modAdd.val = lhs.val + rhs.val;
    modAdd.val %= rhs.mod;
    return modAdd;
  }
  else{
    modAdd.mod = -1;
    modAdd.val = -1;
    return modAdd;
  }
}

int main(){
  ModInt mod1(8,10);
  ModInt mod2(8,12);
  cout << mod1.getValValue() << " , "<< mod2.getValValue() << endl; //tester
  //tester for bool operator ==(ModInt lhs, ModInt rhs)
  if(mod1 == mod2){
    cout << "These two values are equal." << endl;
  }
  else{
    cout << "These two values are not equal." << endl;
  }
  mod1 += mod2;
  cout << mod1.getValValue() << endl;

  ModInt modAdd = mod1 + mod2;
  cout << modAdd.getValValue() << endl;

  return 0;
}
