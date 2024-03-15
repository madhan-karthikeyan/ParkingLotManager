#include <iostream>
#include <vector>
using namespace std;
/*
Features:
1) Add User
2) Register Vehicle
3) Park Vehicle
4) Check if Vehicle is parked
5) Display fare
6) Display user details
7) Display Vehicle details
8) Add amount to wallet
*/

class ParkingLot {
public:
    int VehicleIn;
    int VehicleOut;
};

class Vehicle {
private:
    string LicenseId;
    string VehicleModel;
    string VehicleColor;
    string VehicleType;
    bool Membership;
    bool Parked;
    string SlotNo;
public:
    void addVehicle();
    void displayVehicle();
};

class Car : private Vehicle {
private:
    const int baseFare=200;
    const int hourlyFare=50;
};

class Bike : private Vehicle {
private:
    const int baseFare=100;
    const int hourlyFare=25;
};

// Vehicle Class functions here...
void Vehicle::addVehicle() {
    string op;
    cout << "Enter LicenseID: ";
    cin >> LicenseId;
    cout << "Enter Vehicle Brand: ";
    cin >> VehicleModel;
    cout << "Enter Vehicle color: ";
    cin >> VehicleColor;
    cout << "Enter Vehicle type: (car(c) or bike(b)): ";
    cin >> VehicleType;
    cout << "Add Vehicle to Membership? (yes(y) or no(n)): ";
    cin >> op;
    if (op=="y") {
       Membership = true;
    }
}

void Vehicle::displayVehicle() {
    cout << "License ID: " << LicenseId << endl;
    cout << "Vehicle Model: " << VehicleModel << endl;
    cout << "Vehicle Color: " << VehicleColor << endl;
    cout << "Vehicle Type: " << VehicleType << endl;
    if (Membership==true) {
        cout << "Membership: " << "Yes" << endl;
    } else {
        cout << "Membership: " << "No" << endl;
    }

    // if (Parked==true) {
    //     cout << "Vehicle is parked: " << "Yes" << endl;
    // } else {
    //     cout << "Vehicle is parked: " << "No" << endl;
    // }
    
}

class Slot {
private:
    string SlotNo;
    bool Vacancy;
    int RemainingTime;
};

class Customer {
private: 
    string Name;
    int Age;
    char Gender;
    long int PhoneNumber;
    int WalletAmount;
    int VehiclesRegistered;
    bool MemberShip;
    char MembershipType;
    vector<Vehicle> v;
public:
    void addUser();
    void displayUser();
    void registerVehicle();
    // void showVehilce();
};
// Customer Class functions here...
void Customer::addUser() {
    string op;
    cout << "Enter name: ";
    getline(cin, Name);
    cout << "Enter age: ";
    cin >> Age;
    cout << "Enter Gender (M or F): ";
    cin >> Gender;
    cout << "Enter Phone number: ";
    cin >> PhoneNumber;
    cout << "Add amount to wallet: ";
    cin >> WalletAmount;
    // cout << "No of : ";
    // cin >> Name;
    cout << "Need Membership? (y or n) ";
    cin >> op;
    if (op=="y") {
        cout << "Enter Membership type: (Weekly(w) or Monthly(m) or Yearly(y)): ";
        cin >> MembershipType;
        MemberShip = true;
    } else {
        MemberShip = false;
    }
   
}

void Customer::displayUser() {
    cout << "Name: " << Name << endl;
    cout << "Age: " << Age << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Phone number: " << PhoneNumber << endl;
    cout << "Balance: " << WalletAmount << endl;
    if (MemberShip==true) {
        cout << "Membership: " << "Yes" << endl;
        cout << "Membership type: " << MembershipType << endl;
    } else {
        cout << "Membership: " << "No" << endl;
    }

}

// void Customer::showVehilce() {
    
// }

void Customer::registerVehicle() {
    Vehicle vle;
    vle.addVehicle();
    v.push_back(vle);
    VehiclesRegistered++;
    vle.displayVehicle();
}

int main() {
    Customer c;
    c.addUser();
    c.displayUser();
    c.registerVehicle();

    // c.showVehilce();
    return 0;
}