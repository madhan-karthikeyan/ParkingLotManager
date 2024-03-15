#include <iostream>
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
    int VehicleId;
    string LicenseId;
    string VehicleModel;
    string VehicleColor;
    string VehicleType;
    bool Membership;
    bool parked;
    string SlotNo;
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

class Slot {
private:
    string SlotNo;
    bool Vacancy;
    int RemainingTime;
};

class Customer {
private: 
    int CustomerId;
    string Name;
    int Age;
    char Gender;
    long int PhoneNumber;
    int WalletAmount;
    int VehiclesRegistered;
    bool MemberShip;
    char MembershipType;
public:
    void addUser() {
        string op;
        cout << "Enter name: ";
        getline(cin, Name);
        cout << "Create a User ID: ";
        cin >> CustomerId;
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

    void displayUser() {
        cout << "ID: " << CustomerId << endl;
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
};

int main() {
    Customer c;
    c.addUser();
    c.displayUser();
    return 0;
}