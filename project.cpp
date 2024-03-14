#include <iostream>
using namespace std;
/*
Features:
1) Add User
2) Register Car
3) Park Car
4) Check if car is parked
5) Display fare
6) Display user details
7) Display car details
8) Add amount to wallet
*/

class ParkingLot {
    public:
        int CarIn;
        int CarOut;
};

class Car {
    private:
        int CarId;
        string LicenseId;
        string CarModel;
        string CarColor;
        string CarType;
        bool Membership;
        bool parked;
        string SlotNo;
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
        int CarsRegistered;
        bool MemberShip;
        char MembershipType;
};

int main() {
    int num;
    
    return 0;
}