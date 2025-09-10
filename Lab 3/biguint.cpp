#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class biguint{
public:
  // CONSTANTS & TYPES
  static const std::size_t CAPACITY = 20;

  // CONSTRUCTORS
  biguint(){
    for(int i = 0; i < CAPACITY; i++){
      data_[i] = 0;//set all members in the array to 0
    }
  }

  biguint(const std::string & str){
    string str2 = str;
    for(int i = 0; i < str.length(); i++){
      str2.at(i) = str.at(str.length() - 1 - i);
    }

    for(int j = 0; j < str2.length(); j++){
      data_[j] = str2.at(j) - '0';
    }

    if(str2.length() < CAPACITY){
      for(int k = str.length(); k < CAPACITY; k++){
        data_[k] = 0;
      }
    }
  }

  // CONSTANT MEMBER FUNCTIONS

  unsigned short operator [](std::size_t pos) const;

  // MODIFICATION MEMBER FUNCTIONS

  void operator +=(const biguint & b);

  friend ostream& operator <<(ostream& out, biguint RHS);

private:
   unsigned short data_[CAPACITY];
 };

 unsigned short biguint::operator [](std::size_t pos) const{
   assert(pos < CAPACITY);
   return data_[pos];
 }

 void biguint::operator +=(const biguint & b){
   for(std::size_t i = CAPACITY; i > 0; i--){
     if(data_[i - 1] + b.data_[i - 1] >= 10){
       data_[i - 1] = data_[i - 1] + b.data_[i - 1] - 10;
       data_[i - 2] += 1;
     }

     else{
       data_[i - 1] += b.data_[i - 1];
     }
   }
 }

ostream& operator <<(ostream& output, biguint RHS){
  string STR = " ";
  string str;
  for(int k = 0; k < RHS.CAPACITY; k++){
    STR += to_string(RHS[k]);
  }
  str = STR;
  for(int i = 0; i < STR.length(); i++){
    str.at(i) = STR.at(STR.length() - 1 - i);
  }
  output << str;
  return output;
}

int main(){
  biguint test1 = biguint();
  biguint test2 = biguint("1472");
  cout << test1 << endl;
  cout << test2 << endl;
  return 0;
}
