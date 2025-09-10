//Programming Project 19.13

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

int operatorActions(int o1, int o2, char c){
  int val;
  if(c == '+'){
    val = o1 + o2;
  }

  else if(c == '-'){
    val = o2 - o1;
  }

  else if(c == '*'){
    val = o1 * o2;
  }

  else if(c == '/'){
    val = o2 / o1;
  }
  else{
    cout << "Error! Unable to perform Operator Action! Exiting the program....." << endl;
  }
  return val;
}

int main(){

int o1;
int o2;
int x;
stack<int> s;
char input[40];
cout << "Enter a number. If you do not want to continue this program, press 'q': ";
cin >> input;
while(1){
  if(input[0] == 'q'){
    cout << "The value on the stack is: "<< s.top() << endl;
  }
  else if(input[0] == '+' or input[0] == '-' or input[0] == '*' or input[0] == '/'){
    if(s.size() < 2){
      cout << "Stack requires more operands. Please enter a number or operator.: ";
      cin >> input;
    }

    else{
      o1 = s.top();
      s.pop();
      o2 = s.top();
      s.pop();
      s.push(operatorActions(o1, o2, input[0]));
    }
  }
  else{
    x = atoi(input);
    s.push(x);
  }
  cout << "Would you like to exit the program now? If yes, press 'q'. If not, enter a number or operator.: ";
  cin >> input;
}
  return 0;
}
