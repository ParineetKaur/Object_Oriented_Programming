//Programming Project 19.6
//Part b of question 6

#include <iostream>
#include <ctime>
#include <set>
#include<cstdlib>
using namespace std;


int main(){
  set<int> s;
  set<int>::iterator it;
  int n;
  time_t start, end;
  double diff;
  srand(time(NULL));
  cout << "Enter a value for n: " << endl;
  cin >> n;
  time (&start);
  for(int i = 0; i < n; i++){
    int r = rand()%n;
    it = s.find(r);
    if(it == s.end()){
      s.insert(r);
    }
  }
  time(&end);
  diff = difftime(end,start);
  cout << "It took " << diff << " seconds to execute." << endl;
  cout << "There were " << s.size() << " elements added in the set." << endl;
  return 0;
}
