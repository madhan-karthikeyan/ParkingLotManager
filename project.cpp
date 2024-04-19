#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;



class Vehicle {
private:
    string LicenseId;
    string VehicleModel;
    string VehicleColor;
    bool Membership;
    bool Parked;
    string SlotNo;
    string VehicleType;
public:
    void addVehicle();
    void displayVehicle();
    string getLicenseId() const { return LicenseId; }
    bool isParked() const { return Parked; }
    void setParked(bool parked) { Parked = parked; }
    string getSlotNo() const { return SlotNo; }
    void setSlotNo(string slotNo) { SlotNo = slotNo; }
    string getVehicleType() const { return VehicleType; }
    bool hasMembership() const { return Membership; }
};

class Slot {
private:
    string SlotNo;
    bool Vacancy;
    Vehicle *parkedVehicle;
public:
    Slot(string slotNo) : SlotNo(slotNo), Vacancy(true), parkedVehicle(nullptr) {}
    bool isVacant() const { return Vacancy; }
    void parkVehicle(Vehicle *vehicle);
    void removeVehicle();
};

void Slot::parkVehicle(Vehicle *vehicle) {
    if (isVacant()) {
        parkedVehicle = vehicle;
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
        parkedVehicle->setParked(false);
        parkedVehicle->setSlotNo("");
        Vacancy = true;
        parkedVehicle = nullptr;
        cout << "Vehicle removed from Slot " << SlotNo << endl;
    } else {
        cout << "Slot " << SlotNo << " is already vacant!" << endl;
    }
}

class Customer {
private:
    string Name;
    int Age;
    char Gender;
    long int PhoneNumber;
    int WalletAmount;
    vector<Vehicle*> vehicles;
public:
    void addUser();
    void displayUser();
    void registerVehicle();
    void addAmountToWallet();
    void showVehicles();
    void parkVehicle();
    void removeVehicle();
    bool checkIfVehicleIsParked(string licenseID);
    float fareCalculator(Vehicle *vehicle);
};

void Vehicle::addVehicle() {
    cout << "Enter License ID: ";
    cin >> LicenseId;
    cout << "Enter Vehicle Model: ";
    cin >> VehicleModel;
    cout << "Enter Vehicle Color: ";
    cin >> VehicleColor;
    cout << "Is the vehicle a member (1 for yes, 0 for no): ";
    cin >> Membership;
    Parked = false;
    cout << "Enter vehicle type (Car/Bike): ";
    cin >> VehicleType;
}

void Vehicle::displayVehicle() {
    cout << "License ID: " << LicenseId << endl;
    cout << "Vehicle Model: " << VehicleModel << endl;
    cout << "Vehicle Color: " << VehicleColor << endl;
    cout << "Membership: " << (Membership ? "Yes" : "No") << endl;
    cout << "Parked: " << (Parked ? "Yes" : "No") << endl;
    cout << "Slot No: " << SlotNo << endl;
    cout << "Vehicle Type: " << VehicleType << endl;
}

void Customer::addUser() {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Enter Age: ";
    cin >> Age;
    cout << "Enter Gender (M/F): ";
    cin >> Gender;
    cout << "Enter Phone Number: ";
    cin >> PhoneNumber;
    cout << "Enter Wallet Amount: ";
    cin >> WalletAmount;
}

void Customer::displayUser() {
    cout << "Name: " << Name << endl;
    cout << "Age: " << Age << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Phone Number: " << PhoneNumber << endl;
    cout << "Wallet Amount: " << WalletAmount << endl;
}

void Customer::registerVehicle() {
    Vehicle *newVehicle = new Vehicle();
    newVehicle->addVehicle();
    vehicles.push_back(newVehicle);
    cout << "Vehicle Registered Successfully!" << endl;
}

void Customer::addAmountToWallet() {
    int amount;
    cout << "Enter amount to add to wallet: ";
    cin >> amount;
    WalletAmount += amount;
    cout << "Amount added to wallet successfully!" << endl;
}

void Customer::showVehicles() {
    if (vehicles.empty()) {
        cout << "No vehicles registered!" << endl;
    } else {
        for (int i = 0; i < vehicles.size(); ++i) {
            cout << "Vehicle " << i+1 << ":" << endl;
            vehicles[i]->displayVehicle();
        }
    }
}

void Customer::parkVehicle() {
    string licenseID;
    cout << "Enter License ID of the vehicle to park: ";
    cin >> licenseID;

    if (checkIfVehicleIsParked(licenseID)) {
        cout << "Vehicle is already parked!" << endl;
        return;
    }

    for (Vehicle *vehicle : vehicles) {
        if (vehicle->getLicenseId() == licenseID) {
            Slot *slot = new Slot("A1");
            slot->parkVehicle(vehicle);

            float parkingCharge = fareCalculator(vehicle);
            if (WalletAmount >= parkingCharge) {
                WalletAmount -= parkingCharge;
                cout << "Parking charge of $" << fixed << setprecision(2) << parkingCharge << " deducted from wallet." << endl;
            } else {
                cout << "Insufficient funds in wallet to park the vehicle!" << endl;
            }

            delete slot; // Deallocate memory
            return;
        }
    }

    cout << "Vehicle with License ID " << licenseID << " not found!" << endl;
}

bool Customer::checkIfVehicleIsParked(string licenseID) {
    for (Vehicle *vehicle : vehicles) {
        if (vehicle->getLicenseId() == licenseID && vehicle->isParked()) {
            return true;
        }
    }
    return false;
}

float Customer::fareCalculator(Vehicle *vehicle) {
    float parkingCharge = 0.0;
    if (vehicle->getVehicleType() == "Car") {
        parkingCharge = 200.0;
    } else if (vehicle->getVehicleType() == "Bike") {
        parkingCharge = 100.0;
    }

    if (vehicle->hasMembership()) {
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
