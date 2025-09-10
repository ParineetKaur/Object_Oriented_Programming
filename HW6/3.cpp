//Programming Project 19.3

#include <iostream>
#include <vector>
using namespace std;

int main(){

   vector<int> primes;
   int N;
   cout<<"Enter the value of N: ";
   cin >> N;

   bool* flags = new bool[N+1];
   for(int i=0; i<=N; i++){
     flags[i]=true;
   }
   flags[0] = false;
   flags[1] = false;
   int tester = 2;

   while(tester <= N){
       for(int x=2*tester; x<=N; x+=tester){
           flags[x] = false;
       }
       tester += 1;
       while(flags[tester]==false){
         tester += 1;
       }
   }

   for (int l = 0; l <= N; l++){
     if (flags[l]){
       primes.push_back(l);
     }
   }

   // print the vector
   cout<<"Primes between 1 and "<< N << endl;
   for(unsigned int i = 0; i < primes.size(); i++){
     cout << primes[i] << " " << endl;
   }

   return 0;
}
