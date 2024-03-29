#include <iostream>
#include <vector>
using namespace std;

class ParkingLot {
public:
    int VehicleIn;
    int VehicleOut;
};

class Vehicle {
private:
    string VehicleId;
    string VehicleModel;
    string VehicleColor;
    bool Membership;
    bool Parked;
    string SlotNo;
public:
    string VehicleType;
    void addVehicle();
    void displayVehicle(string); //VehicleID
};

class Slot {
private:
    int SlotNo;
    bool Vacancy;
    int RemainingTime;
    string vehicleID;
public:
    float fareCalculator(); //Kept for debugging purposes
    void parkVehicle(string); //VehicleID
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
    string Passwd;
    vector<Vehicle> vehicles;
public:
    // The two strings are for username and password
    void addUser();
    void displayUser(string, string);
    void registerVehicle(string, string);
    void addAmountToWallet(string, string);
    void showVehilce(string, string);
};

void Customer::addUser() {
    string op, Passwd, temp2;
    cout << "Enter name(without spaces): ";
    cin >> Name;
    cout << "Create new password(without spaces): ";
    cin >> Passwd;
    cout << "Confirm password: ";
    cin >> temp2;
    if (Passwd.compare(temp2)==0) {
        this->Passwd = Passwd;
        cout << "Password created successfully.!!" << endl;
    }
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

void Customer::displayUser(string userName, string passwd) {
    
}
/*
Price list:
Car: Base fare-200, hourly 100
Bike: Base fare-100, hourly 50
Membership discount:
Weekly- 3% (Charges 500 /week)
Monthly- 5% (Charges 2500 /month)
Yearly- 15% (Charges 10000 /year)
*/

int main() {
    vector<Customer> customer;
        Slot s;
    int choice;
    string vType;
    do {
        Customer c;
        cout << "1) Add User" << endl;
        cout << "2) Register Vehicle" << endl;
        cout << "3) Deposit amount to wallet" << endl;
        cout << "4) Calculate fare" << endl;
        cout << "5) Show user details" << endl;
        cout << "6) Show vehicle details" << endl;
        cout << "7) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            c.addUser();
            break;
        case 2:
            // c.registerVehicle();
            break;
        case 3:
            // c.addAmountToWallet();
            break;
        case 4:
            s.fareCalculator();
            break;
        case 5:
            // c.displayUser();
            break;
        case 6:
            // c.showVehilce();
            break;
        case 7:
            // s.parkVehicle();
        case 8:
            "Thank you, come again later :)";
            break;
        }
        customer.push_back(c);
        if (choice==7) {
            break;
        }
        cout << endl;

    } while ((choice<=9) && (choice>0));
    
    return 0;
}

