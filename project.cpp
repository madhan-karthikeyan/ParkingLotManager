#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Creating two base classes: Person and Vehicle

class Person {
protected:
    string Name;
    int Age;
    char Gender;
    string PhoneNumber;
public:
    virtual void addUser() = 0;
    virtual void displayUser() = 0;
};

class Vehicle {
protected:
    string LicenseId;
    string VehicleModel;
    string VehicleColor;
    bool Membership;
    bool Parked;
    string SlotNo;
    string VehicleType;
public:
    virtual void addVehicle() = 0;
    virtual void displayVehicle() = 0;
    virtual float fareCalculator() = 0;
    virtual bool isParked() const { return Parked; }
    virtual void setParked(bool parked) { Parked = parked; }
    virtual string getLicenseId() const { return LicenseId; }
    virtual string getSlotNo() const { return SlotNo; }
    virtual void setSlotNo(string slotNo) { SlotNo = slotNo; }
    virtual string getVehicleType() const { return VehicleType; }
    virtual bool hasMembership() const { return Membership; }
};


class Car : public Vehicle {
public:
    void addVehicle() override {
        cout << "Enter License ID: ";
        cin >> LicenseId;
        cout << "Enter Vehicle Model: ";
        cin >> VehicleModel;
        cout << "Enter Vehicle Color: ";
        cin >> VehicleColor;
        cout << "Is the vehicle a member (1 for yes, 0 for no): ";
        cin >> Membership;
        Parked = false;
        VehicleType = "Car";
    }

    void displayVehicle() override {
        cout << "License ID: " << LicenseId << endl;
        cout << "Vehicle Model: " << VehicleModel << endl;
        cout << "Vehicle Color: " << VehicleColor << endl;
        cout << "Membership: " << (Membership ? "Yes" : "No") << endl;
        cout << "Parked: " << (Parked ? "Yes" : "No") << endl;
        cout << "Slot No: " << SlotNo << endl;
        cout << "Vehicle Type: " << VehicleType << endl;
    }

    float fareCalculator() override {
        float parkingCharge = 200.0;
        if (hasMembership()) {
            char membershipType;
            cout << "Enter membership type (W for Weekly, M for Monthly, Y for Yearly): ";
            cin >> membershipType;
            switch (membershipType) {
                /*
                3% discount for weekly membership
                5% discount for monthly membership
                15% discount for yearly membership
                */
                case 'W':
                    parkingCharge *= 0.97;
                    break;
                case 'M':
                    parkingCharge *= 0.95;
                    break;
                case 'Y':
                    parkingCharge *= 0.85;
                    break;
                default:
                    cout << "Invalid membership type!" << endl;
            }
        }
        return parkingCharge;
    }
};

class Bike : public Vehicle {
public:
    void addVehicle() override {
        cout << "Enter License ID: ";
        cin >> LicenseId;
        cout << "Enter Vehicle Model: ";
        cin >> VehicleModel;
        cout << "Enter Vehicle Color: ";
        cin >> VehicleColor;
        cout << "Is the vehicle a member (1 for yes, 0 for no): ";
        cin >> Membership;
        Parked = false;
        VehicleType = "Bike";
    }

    void displayVehicle() override {
        cout << "License ID: " << LicenseId << endl;
        cout << "Vehicle Model: " << VehicleModel << endl;
        cout << "Vehicle Color: " << VehicleColor << endl;
        cout << "Membership: " << (Membership ? "Yes" : "No") << endl;
        cout << "Parked: " << (Parked ? "Yes" : "No") << endl;
        cout << "Slot No: " << SlotNo << endl;
        cout << "Vehicle Type: " << VehicleType << endl;
    }

    float fareCalculator() override {
        float parkingCharge = 100.0;
        if (hasMembership()) {
            char membershipType;
            cout << "Enter membership type (W for Weekly, M for Monthly, Y for Yearly): ";
            cin >> membershipType;
            switch (membershipType) {
                case 'W':
                    parkingCharge *= 0.97;
                    break;
                case 'M':
                    parkingCharge *= 0.95;
                    break;
                case 'Y':
                    parkingCharge *= 0.85;
                    break;
                default:
                    cout << "Invalid membership type!" << endl;
            }
        }
        return parkingCharge;
    }
};

class Slot {
private:
    string SlotNo;
    bool Vacancy;
    vector<Vehicle*> parkedVehicles; // Collection of vehicles parked in the slot
public:
    Slot(string slotNo) : SlotNo(slotNo), Vacancy(true) {}
    bool isVacant() const { return Vacancy; }
    void parkVehicle(Vehicle *vehicle);
    void removeVehicle();
};

void Slot::parkVehicle(Vehicle *vehicle) {
    if (isVacant()) {
        parkedVehicles.push_back(vehicle);
        vehicle->setParked(true);
        vehicle->setSlotNo(SlotNo);
        Vacancy = false;
        cout << "Vehicle parked successfully in Slot " << SlotNo << endl;
    } else {
        cout << "Slot " << SlotNo << " is already occupied!" << endl;
    }
}

void Slot::removeVehicle() {
    if (!isVacant()) {
        // Remove the vehicle from the parked vehicles list
        parkedVehicles.pop_back(); // Assuming you remove the last parked vehicle
        // If the slot is empty after removing the vehicle, update vacancy status
        if (parkedVehicles.empty()) {
            Vacancy = true;
            cout << "Slot " << SlotNo << " is now vacant." << endl;
        }
        cout << "Vehicle removed from Slot " << SlotNo << endl;
    } else {
        cout << "Slot " << SlotNo << " is already vacant!" << endl;
    }
}
class Customer : public Person {
private:
    int WalletAmount;
    vector<Vehicle*> vehicles;
public:
void addUser() override {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, Name);

    cout << "Enter Age: ";
    cin >> Age;
    while (Age < 18) {
        cout << "Age must be 18 or above. Enter Age again: ";
        cin >> Age;
    }

    cout << "Enter Gender (M/F): ";
    cin >> Gender;

    cout << "Enter Phone Number: ";
    cin >> PhoneNumber;
    while (PhoneNumber.length() != 10) {
        cout << "Phone Number must be exactly 10 digits. Enter Phone Number again: ";
        cin >> PhoneNumber;
    }

    cout << "Enter Wallet Amount: ";
    cin >> WalletAmount;
}


    void displayUser() override {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << Gender << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Wallet Amount: " << WalletAmount << endl;
    }

    void registerVehicle() {
        char choice;
        cout << "Enter vehicle type (C for Car, B for Bike): ";
        cin >> choice;
        Vehicle *newVehicle;
        if (choice == 'C') {
            newVehicle = new Car();
        } else if (choice == 'B') {
            newVehicle = new Bike();
        } else {
            cout << "Invalid vehicle type!" << endl;
            return;
        }
        newVehicle->addVehicle();
        vehicles.push_back(newVehicle);
        cout << "Vehicle Registered Successfully!" << endl;
    }

    void addAmountToWallet() {
        int amount;
        cout << "Enter amount to add to wallet: ";
        cin >> amount;
        WalletAmount += amount;
        cout << "Amount added to wallet successfully!" << endl;
    }

    void showVehicles() {
        if (vehicles.empty()) {
            cout << "No vehicles registered!" << endl;
        } else {
            for (int i = 0; i < vehicles.size(); ++i) {
                cout << "Vehicle " << i+1 << ":" << endl;
                vehicles[i]->displayVehicle();
            }
        }
    }

    void parkVehicle() {
        string licenseID;
                Slot *slot = new Slot("A1");
                slot->parkVehicle(vehicle);

                float parkingCharge = vehicle->fareCalculator();
                if (WalletAmount >= parkingCharge) {
                    WalletAmount -= parkingCharge;
                    cout << "Parking charge of Rs." << fixed << ((int)(parkingCharge * 100)) / 100.0 << " deducted from wallet." << endl;
                } else {
                    cout << "Insufficient funds in wallet to park the vehicle!" << endl;
                }

                delete slot; // Deallocate memory
                return;
            }
        }

        cout << "Vehicle with License ID " << licenseID << " not found!" << endl;
    }
};

void menu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Register Vehicle" << endl;
    cout << "2. Add Amount to Wallet" << endl;
    cout << "3. Show Vehicles" << endl;
    cout << "4. Park Vehicle" << endl;
    cout << "5. Display User Details" << endl;
    cout << "6. Exit" << endl;
    cout << "================" << endl;
}

int main() {
    int userCount;
    cout << "Enter the number of users: ";
    cin >> userCount;
    Customer *users = new Customer[userCount];

    if (userCount <= 0) {
        cout << "Invalid number of users!" << endl;
        delete[] users; // Deallocate memory
        return 1;
    }

    for (int i = 0; i < userCount; ++i) {
        cout << "User " << i+1 << ":" << endl;
        users[i].addUser();
    }

    int choice;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter user number to register vehicle: ";
                int userNumRegister;
                cin >> userNumRegister;
                if (userNumRegister >= 1 && userNumRegister <= userCount) {
                    users[userNumRegister - 1].registerVehicle();
                } else {
                    cout << "Invalid user number!" << endl;
                }
                break;
            case 2:
                cout << "Enter user number to add amount to wallet: ";
                int userNumAddAmount;
                cin >> userNumAddAmount;
                if (userNumAddAmount >= 1 && userNumAddAmount <= userCount) {
                    users[userNumAddAmount - 1].addAmountToWallet();
                } else {
                    cout << "Invalid user number!" << endl;
                }
                break;
            case 3:
                cout << "Enter user number to show vehicles: ";
                int userNumShowVehicles;
                cin >> userNumShowVehicles;
                if (userNumShowVehicles >= 1 && userNumShowVehicles <= userCount) {
                    users[userNumShowVehicles - 1].showVehicles();
                } else {
                    cout << "Invalid user number!" << endl;
                }
                break;
            case 4:
                cout << "Enter user number to park vehicle: ";
                int userNumParkVehicle;
                cin >> userNumParkVehicle;
                if (userNumParkVehicle >= 1 && userNumParkVehicle <= userCount) {
                    users[userNumParkVehicle - 1].parkVehicle();
                } else {
                    cout << "Invalid user number!" << endl;
                }
                break;
            case 5:
                cout << "Enter user number to display details: ";
                int userNumDisplayDetails;
                cin >> userNumDisplayDetails;
                if (userNumDisplayDetails >= 1 && userNumDisplayDetails <= userCount) {
                    users[userNumDisplayDetails - 1].displayUser();
                } else {
                    cout << "Invalid user number!" << endl;
                }
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != 6);

    delete[] users; // Deallocate memory
    return 0;
}