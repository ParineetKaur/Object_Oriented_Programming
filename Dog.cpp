#include <iostream>
using namespace std;

class HotDogStand{
private:
  int id;
  int soldToday;
  static int soldAllStands;
public:
  HotDogStand();
  HotDogStand(int newID, int sold);
  void JustSold();
  int getnumSold();
  static int GetNumSoldAllStands();
};
//static variable to 0
int HotDogStand::soldAllStands = 0;

HotDogStand::HotDogStand() : id(0), soldToday(0)
{
}

HotDogStand::HotDogStand(int newID, int sold){
  id = newID;
  soldToday = sold;
  soldAllStands += sold;
}

void HotDogStand::JustSold(){
  soldToday++;
  soldAllStands++;
}

int HotDogStand::getnumSold(){
  return soldToday;
}

int HotDogStand::GetNumSoldAllStands(){
  return soldAllStands;
}

int main(){
  HotDogStand stand1, stand2(1,4), stand3(2,0);
  cout << "All sales: " << stand1.GetNumSoldAllStands() << endl;
  cout << "_________________________________" << endl;
  cout << "Two sales at stand 1" << endl;
  stand1.JustSold();
  stand1.JustSold();
  cout << "All sales: " << stand1.GetNumSoldAllStands() << endl;
    cout << "_________________________________" << endl;
  cout << "One sale at stand 2" << endl;
  stand2.JustSold();
  cout << "Three sales at stand 3" << endl;
  stand3.JustSold();
  cout << "All sales: " << stand1.GetNumSoldAllStands() << endl;
    cout << "_________________________________" << endl;
  return 0;
}
