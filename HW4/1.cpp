//Answers 14.1 Programming Project Question

#include <iostream>
#include <string>
using namespace std;

class Employee{
public:
   Employee(){
     name = "No Name Yet";
     ssn = "No Number Yet";
     netPay = 0;
   }
   Employee(const string& theName, const string& theNumber){
     name = theName;
     ssn = theNumber;
     netPay = 0;
   }
   string getName() const{
     return name;
   }
   string getSsn() const{
     return ssn;
   }
   double getNetPay() const{
     return netPay;
   }
   void setName(const string& newName){
     name = newName;
   }
   void setSsn(const string& Ssn){
     ssn = Ssn;
   }
   void setNetPay(double newNetPay){
     netPay = newNetPay;
   }
   void printCheck() const{
     cout << "\nERROR: printCheck function called for an " << endl;
     cout << "UNDIFFERENTIATED Employee. Aborting the program." << endl;
     cout << "Check with the author of the program about this bug." << endl;
     exit(1);
   }
 protected:
   string name;
   string ssn;
   double netPay;
};

 class SalariedEmployee : public Employee{
 public:
   SalariedEmployee() : Employee() , salary(0){}
   SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary){
     Employee(theName, theSsn);
     salary = theWeeklySalary;
     }
   double getSalary(){
     return salary;
   }
   void setSalary(double newSalary){
     salary = newSalary;
   }
   void printCheck(){
     setNetPay(salary);
     cout << "\n_____________________________\n";
     cout << "Pay to the order of " << getName() << endl;
     cout << "The sum of " << getNetPay() << endl;
     cout << "\n_____________________________\n";
     cout << "Check Stub not NEGOTIABLE\n";
     cout << "Employee Number: " << getSsn() << endl;
     cout << "Salaried Employee. Regular Pay: " << salary << endl;
     cout << "\n_____________________________\n";
   }

 protected:
   double salary;
 };

 class Administrator : public SalariedEmployee{
 private:
   string adminTitle;
   string areaOfResponsibility;
   string adminSupervisor;

 protected:
   double annualSalary;

 public:
   void setSupervisor(const string& newSupervisorName){
     adminSupervisor = newSupervisorName;
   }
   string getSupervisorName(){
     return adminSupervisor;
   }
   void input(){
     cout << "Provide the adminisrator's title: " << endl;
     cin >> adminTitle;
     cout << "Provide the adminisrator's Area of Responsibility: " << endl;
     cin >> areaOfResponsibility;
     cout << "Provide the adminisrator's Supervisor's name: " << endl;
     cin >> adminSupervisor;
     cout << "Provide the adminisrator's annual salary: " << endl;
     cin >> annualSalary;
   }
   void print(){
     cout << "Administrator's title: " << adminTitle << endl;
     cout << "Administrator's Area of Responsibility: " << areaOfResponsibility << endl;
     cout << "Administrator's Annual Salary: $" << annualSalary << endl;
     cout << "Administrator's Supervisor's Name: " << adminSupervisor << endl;
   }
   void printCheck(){
     setNetPay(salary);
     cout << "\n_____________________________\n";
     cout << "Pay to the order of " << getName() << endl;
     cout << "The sum of " << getNetPay() << endl;
     cout << "\n_____________________________\n";
     cout << "Check Stub not NEGOTIABLE\n";
     cout << "Employee Number: " << getSsn() << endl;
     cout << "Salaried Employee. Regular Pay: " << salary << endl;
     cout << "\n_____________________________\n";
   }
 };

 int main(){
   Administrator test1;
   string SupervisorName = "George Gill";
   test1.setSupervisor(SupervisorName);
   cout << "The Supervisor's name is now " << test1.getSupervisorName() << endl;
   cout << "_____________________________________" << endl;
   cout << "Begin Inputting: " << endl;
   test1.input();
   cout << endl;
   cout << "_____________________________________" << endl;
   cout << "You inputed the following: " << endl;
   test1.print();
   return 0;
 }
