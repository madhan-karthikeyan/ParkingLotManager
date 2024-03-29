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

class Slot {
private:
    int SlotNo;
    bool Vacancy;
    int RemainingTime;
    string vehicleID;
public:
    float fareCalculator();
    void parkVehicle();
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
    void addUser();
    void displayUser(string, string);
    void registerVehicle(string, string);
    void addAmountToWallet(string, string);
    void showVehilce(string, string);
};
