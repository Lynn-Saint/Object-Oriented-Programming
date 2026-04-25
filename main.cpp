#include <iostream>
#include <string>
using namespace std;

class vehicle {
private:
  string brand;
  string model;
  int year;

public:
  vehicle(string a, string b, int date) {
    brand = a;
    model = b;
    year = date;
  }

  virtual string GetInfo() {
    return "Brand: " + brand + ", Model: " + model +
           ", Year: " + to_string(year); // series of catenation + casting.
  }
};
class Car : public vehicle {
private:
  int Doors;

public:
  Car(string a, string b, int date, int doors) : vehicle(a, b, date) {
    Doors = doors;
  }
  string GetInfo() override {
    return vehicle::GetInfo() + ", Doors: " + to_string(Doors);
  }
};

class Motorcycle : public vehicle {
private:
  bool hasSideCar;

public:
  Motorcycle(string a, string b, int date, bool sidecar) : vehicle(a, b, date) {
    hasSideCar = sidecar;
  }

  string GetInfo() override {
    string sidecarInfo = hasSideCar ? "Yes" : "No";
    return vehicle::GetInfo() + ", Sidecar: " + sidecarInfo;
  }
};

int main() {
  string brand, model;
  int date, doors;

  cout << "Enter Your Car Information(brand): ";
  cin >> brand;

  cout << "Enter Your Car Information(model): ";
  cin >> model;

  cout << "Enter Your Car Information(Year): ";
  cin >> date;

  cout << "Enter Your Car Information(Doors): ";
  cin >> doors;

  Car car1(brand, model, date, doors);
  Motorcycle mCycle("Yamaha", "R1", 2021, false);

  cout << "\nCar Info: \n" << car1.GetInfo() << endl;
  cout << "\nMotorcycle Info: \n" << mCycle.GetInfo() << endl;

  return 0;
}