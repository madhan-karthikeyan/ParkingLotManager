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
    bool Membership;
    bool Parked;
    string SlotNo;
public:
    string VehicleType;
    void addVehicle();
    void displayVehicle();
};

class Car : private Vehicle {
public:
    const float baseFare=200.0;
    const float hourlyFare=50.0;
};

class Bike : private Vehicle {
public:
    const float baseFare=100.0;
    const float hourlyFare=25.0;
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
    } else {
        Membership = false;
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
    cout << endl;
    // if (Parked==true) {
    //     cout << "Vehicle is parked: " << "Yes" << endl;
    // } else {
    //     cout << "Vehicle is parked: " << "No" << endl;
    // }
    
}

class Slot {
private:
    int SlotNo;
    bool Vacancy;
    int RemainingTime;
public:
    float fareCalculator(float, string);
    void parkVehicle();
};

// Slot Class functions here...
float Slot::fareCalculator(float hours, string vType) {
    float fare, num;
    num = hours - 1.0;
    Car c;
    Bike b;
    if (vType.compare("c")==0) {
        fare += c.baseFare;
        fare += (num*c.hourlyFare);
    } else if (vType.compare("b")==0) {
        fare += b.baseFare;
        fare += (num*b.hourlyFare);
    }
    cout << fare << endl;
    return fare;

}

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
    vector<Vehicle> v;
public:
    void addUser();
    void displayUser();
    void registerVehicle();
    void addAmountToWallet();
    void showVehilce();
};
// Customer Class functions here...
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

void Customer::showVehilce() {
    for (int i=0; i<v.size(); i++) {
        v[i].displayVehicle();
        cout << endl;
    }
}

void Customer::registerVehicle() {
    Vehicle vle;
    vle.addVehicle();
    v.push_back(vle);
    VehiclesRegistered++;
    cout << "Vehicle registered successfully!!" << endl;
}

void Customer::addAmountToWallet() {
    int num;
    cout << "Enter amount: ";
    cin >> num;
    WalletAmount += num;
    cout << "Amount added successfully!!" << endl;
}
/*
Assumptions for parking lot:
This building has 3 floors
each floor has 99 slots 
With named as:
1-99 in ground floor
100-199 in first floor
200-299 in second floor
*/
int main() {
    vector<Customer> customer;
    Slot s;
    int choice;
    string vcle1;
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
        switch (choice)
        {
        case 1:
            c.addUser();
            customer.push_back(c);
            break;
        case 2:
            c.registerVehicle();
            break;
        case 3:
            c.addAmountToWallet();
            break;
        case 4:
            float hours;
            cout << "Enter duration(in hours): ";
            cin >> hours;
            cout << "Enter car(c) or bike(b): ";
            cin >> vcle1;
            cout << "Your fare is " << s.fareCalculator(hours, vcle1) << endl;  
            break;
        case 5:
            c.displayUser();
            break;
        case 6:
            c.showVehilce();
            break;
        case 7:
            "Thank you, come again later :)";
            break;
        }
        if (choice==7) {
            break;
        }
        cout << endl;

    } while ((choice<=7) && (choice>0));

    
    return 0;
}