
#include <iostream>
using namespace std;

class Student{
public:
  Student(){
    name = "";
    numClasses = 0;
  }
  Student(string studentName);
  Student(const Student& list);
  ~Student(){
    delete [] classList;
  }

  void setName(string studentName);
  string getName();
  int getNumClasses();
  string *getClassList(){
    return classList;
  }

  void input();

  void output();

  void reset();

  void operator =(Student list);


private:
  string name;
  int numClasses;
  string *classList;
};

Student::Student(string studentName){
  name = studentName;
}

void Student::setName(string studentName){
   name = studentName;
 }

string Student::getName(){
  return name;
}

int Student::getNumClasses(){
  return numClasses;
}

void Student::input(){
  cout << "Enter student's name: " << endl;
  cin >> name;
  cout<<"Enter number of courses taken: " << endl;
  cin >> numClasses;
  classList = new string[numClasses];
  cout<<"Enter " << numClasses <<" course names: "<< endl;
  for(int j = 0; j < numClasses; j++){
    getline(cin, classList[j]);
  }
}

void Student::output(){
  cout << "A student named, " << name << " ,has enrolled for "<< numClasses << " courses: "<< endl;
  for(int i=0; i<numClasses; i++){
    if(i < numClasses-1){
      cout << classList[i] << ", ";
    }
    else{
      cout << classList[i] << endl;
    }
  }
}

void Student::reset(){
  numClasses = 0;
  delete [] classList;
}

int main(){
  char enter;
  Student student1;
  cout << "Do you want to begin entering data and receiving data? (y/n): " << endl;
  cin >> enter;
  if(enter == 'y'){
    student1.input();
    student1.output();
    student1.reset();
  }
  if(enter == 'n'){
    exit(1);
  }
  return 0;
}
