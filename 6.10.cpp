//Question 6.10 from Programming Lab Homework

#include <iostream>
#include <iomanip>
using namespace std;



class Temperature{
public:
  void setTempKelvin(double tempKelvin);
  void setTempCelsius(double tempCelsius);
  void setTempFahrenheit(double tempFahrenheit);
  double convertCelsius();
  double convertFahrenheit();
  double convertKelvin();
  Temperature(){
    Temp = 0;
  }
  double Temp;
};

void Temperature::setTempKelvin(double tempKelvin){
  Temp = tempKelvin;
}
void Temperature::setTempCelsius(double tempCelsius){
  Temp = tempCelsius + 273.15;
}
void Temperature::setTempFahrenheit(double tempFahrenheit){
  double celsius = ((5.0/9.0)*(tempFahrenheit-32));
  setTempCelsius(celsius);
}
double Temperature::convertCelsius(){
  double CelsiusVal = Temp - 273.15;
  return CelsiusVal;
}
double Temperature::convertFahrenheit(){
  double tempFahrenheit = Temp - 273.15;
  double fahrenheit = (tempFahrenheit*(9.0/5.0)+32);
  return fahrenheit;
}
double Temperature::convertKelvin(){
  double kelvin = Temp;
  return kelvin;
}

int main(){
  cout << fixed << showpoint;
  cout << setprecision(2);
  Temperature tempCalculation;
  double kelvinTemp;
  double celsiusTemp;
  double fahrenheitTemp;
  cout << "Enter a temperature in fahrenheit: " << endl;
  cin >> fahrenheitTemp;
  tempCalculation.setTempFahrenheit(fahrenheitTemp);
  cout << "The temperature in Kelvin for this value is: " << tempCalculation.Temp << "K." << endl;
  celsiusTemp = tempCalculation.convertCelsius();
  cout << "The temperature in Celsius for this value is: " << celsiusTemp << " degrees C."<< endl;
  return 0;
}
