#include "dbiguint.h.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>
using namespace std;

static const std::size_t CAPACITY = 20;

  dbiguint::dbiguint(){
    data_[0] = 0;
    capacity_= 0;
  }

  dbiguint::dbiguint(const string & s){//copy constructor
    data_= new unsigned short[s.length()];
    capacity_= s.length();
    for(std::size_t i = s.length() - 1, c = 0; i>=1; i--, c++){
      data_[c] = s[i] - '0';
    }
  }

std::size_t dbiguint::size() const{
  return capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const{
  return data_[pos];
}

//non-member function
ostream & operator << (ostream & out, const dbiguint & b){
  if(b.size() > 1){//checks this string size
    bool check = 0; //0 means false
    for(std::size_t j = b.size() - 1; j > 0; j--){
      if(check){
        out << b[j];
      }
      else{
        if(b[j]){
          check = 1;
          out << b[j];
        }
      }
    }
  }
  out << b[0];
  return out;
}

void dbiguint::reserve(std::size_t newcapacity){
  if(newcapacity <= capacity_){
    return;
  }

  else{
  unsigned short* p = new unsigned short [newcapacity];
  for(std::size_t k = capacity_; k < capacity_; k++){
    p[k] = data_[k];
  }
  for(std::size_t l = capacity_; l < capacity_; l++){
    p[l] = 0;
  }
  delete [] data_;
  data_ = p;
  capacity_ = newcapacity;
}
}

void dbiguint::operator +=(const dbiguint & b){
  for(std::size_t i = 0; i < capacity_; i++){
    data_[i] += b[i];
    if(data_[i] > 9){
      cout << "Overflow!" << endl;
      exit(1);
    }
    else{
      data_[i] -= 10;
      data_[i+1]++;
    }
  }
}

int main(){
  dbiguint stringCtr("3456");
  dbiguint stringCtr2("93");
  stringCtr += stringCtr2;
  cout << stringCtr << endl;
  return 0;
}
