#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student{
private:
  string name;
  int grade;
public:
  Student(string n, int g) : name(n) , grade(g){}
  //accessors
  string getName() const{
    return name;
  }
  int getGrade() const{
    return grade;
  }
  friend ostream& operator <<(ostream& out, const Student& RHS);
  bool compareByGrade(const Student& x, const Student& y);
};

ostream& operator <<(ostream& out, const Student& RHS){
  out << RHS.name << " -> " << RHS.grade << endl;
  return out;
}

bool Student::compareByGrade(const Student& x, const Student& y){
  return x.getGrade() < y.getGrade();
}

int main(){
  vector<Student> students;
  //make a list of students
  for(int i = 0; i < 5; i++){
    //random grades and names
    students.push_back(Student("Student", 65 + rand()%10));
  }
  //Printing out vector using normal for loop with i
  for(int j = 0; j < students.size(); j++){
    cout << students[j]; //this will not work without the ostream function because students refers to two variables within Student class
  }
  cout << "Using iterator now: " << endl;
  //Printing out vector using an iterator
  for(vector<Student>::iterator it = students.begin(); it != students.end(); it++){
    cout << *it;
  }
  //duplicating list
  vector <Student> newList;
  newList = students;

  Student x("Amy",70);
  Student y("John",50);
  cout << "Is " << x.getName() << "'s grade less than that of " << y.getName() << "?: " << x.compareByGrade(x, y) << endl;
  return 0;
}
