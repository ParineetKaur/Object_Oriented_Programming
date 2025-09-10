#include <iostream>
using namespace std;

class ModInt{
public:
  //constructors
  ModInt(){
    mod = 0;
    val = 0;
  }

  ModInt(int m, int v){
    mod = m;
    val = v % mod;
  }

  //getters
  int getMod(){
    return mod;
  }
  int getVal(){
    return val;
  }

  friend bool operator ==(ModInt lhs, ModInt rhs);
  void operator +=(ModInt rhs);
  ModInt operator +(ModInt lhs, ModInt rhs);
private:
  int mod;
  int val;
};

bool operator ==(ModInt lhs, ModInt rhs){
  if((lhs.val % lhs.mod) == (rhs.val % rhs.mod)){
    return 1;
  }
  else{
    return 0;
  }
}

void ModInt::operator +=(ModInt rhs){
  if(mod == rhs.mod){
    val+=rhs.val;
    val %= rhs.mod;
  }
  else{
    mod = -1;
    val = -1;
  }
}

ModInt ModInt::operator +(ModInt lhs, ModInt rhs){
  return ((lhs.val % lhs.mod) + (rhs.val % rhs.mod));
}


int main(){
  ModInt mod1, mod2(8,12);
  cout << "Mod 1: " << mod1.getVal() << endl;
  cout << "Mod 2: " << mod2.getVal() << endl;

  cout << "_______________________________________" << endl;
  if(mod1 == mod2){
    cout << "Both are equal!" << endl;
  }
  else{
    cout << "Both are not equal!" << endl;
  }
  return 0;
}
