//Programming Project 19.6
//Part a of question 6

#include <iostream>
#include <ctime>
#include<cstdlib>
#include <vector>
using namespace std;

int main(){
  int n;
  bool found = false;
  int count = 0;
  vector<int> v;
  cout << "Enter an unsigned integer value.: ";
  cin >> n;
  time_t start, end;
  double diff;
  time (&start);
  int r = rand()%n;
  v.push_back(r);
  for(int i = 0; i < n; i++){
    r = rand()%n;
    while(count!=v.size()){
      if(r==v[count]){
        found = true;
      }
      count++;
    }
    if(found == false){//if found continues to be 0, then the randomized r value is aded to the vector
      v.push_back(r);
    }
  }
  time(&end);
  diff = difftime(end,start);
  cout << "It took " << diff << " seconds to execute." << endl;
  cout << "Number of elemenets added to the vector: " << v.size() << endl;
  return 0;
}
