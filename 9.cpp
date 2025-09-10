//Question 7.9

#include <iostream>
#include <string>
using namespace std;

class Zip_Code{
public:
  Zip_Code(int code){
    if(code<10000 || code>99999){
      cout <<"This is an invalid bar code." << endl;
    }
    else{
    zip_code = code;
  }
}

  Zip_Code(string code){
    if(code.length() > 27){
      cout <<"This is an invalid bar code." << endl;
    }
    else{
      int z = 0;
      string str = code.substr(1,code.length()-2);
      for(int i=0; i < str.length()-5; i+=5){
        int sum = 0;
        sum = 7*(str[i]-'0') + 4*(str[i+1]-'0') + 2*(str[i+2]-'0') + 1*(str[i+3]-'0');
        if(sum == 11){
          sum = 0;
        }
        z = z*10 + sum;
      }
      zip_code = z;
    }
  }

  string getZipcode(){
    string str = "1";
    int o = zip_code/10000;
    int s = (zip_code - o*10000)/1000;
    int t = (zip_code - o*10000-s*1000)/100;
    int f = (zip_code - o*10000-s*1000-t*100)/10;
    int l = (zip_code - o*10000-s*1000-t*100-f*10);
    str.append(getString(o));
    str.append(getString(s));
    str.append(getString(t));
    str.append(getString(f));
    str.append(getString(l));
    str.append("1");
    return str;
  }

private:
  int zip_code;
  string getString(int n){//private member function
  string str;

  if(n == 0){
    return "11000";
  }

  if(n > 7){
    str.append("1");
    n = n - 7;
  }
  else{
    str.append("0");
  }

  if(n > 4){
    str.append("1");
    n = n - 4;
  }
  else{
    str.append("0");
  }

  if(n > 2){
    str.append("1");
    n = n - 2;
  }
  else{
    str.append("0");
  }

  if(n > 1){
    str.append("1");
    n = n - 1;
  }
  else{
    str.append("0");
    str.append("0");
  }

return str;
}

int getCode(){//private member function (getter)
  return zip_code;
}

};

int main(){
  Zip_Code zip1(94569);
  Zip_Code zip2(94012);
  cout << zip1.getZipcode() << endl;
  cout << zip2.getZipcode() << endl;
  return 0;
}
