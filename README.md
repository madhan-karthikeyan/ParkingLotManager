# ParkingLotManager
# Parking Lot Management System

## Overview
This program is a simple parking lot management system implemented in C++. It allows users to register vehicles, add funds to their wallet, park vehicles, and view their details and registered vehicles. The program is built using Object-Oriented Programming (OOP) concepts.
Classes blueprint: https://roadmap.sh/r/embed?id=65f27805b9800126875c5f09 <br />

## Features
- **User Management**: Users can register with their name, age, gender, phone number, and initial wallet amount.
- **Vehicle Registration**: Users can register vehicles such as cars and bikes, providing details like license ID, vehicle model, vehicle color, and membership status.
- **Wallet Management**: Users can add funds to their wallet.
- **Parking**: Users can park their registered vehicles in the parking lot, with parking charges deducted from their wallet.
- **Display Details**: Users can view their details and registered vehicles.
- **Multiple Users**: The program supports multiple users, allowing each user to manage their own vehicles and wallet independently.

## Classes and Inheritance
The program is structured using the following classes and inheritance relationships:
- **Person**: Base class representing a person, with attributes like name, age, gender, and phone number.
- **Vehicle**: Base class representing a vehicle, with attributes like license ID, vehicle model, vehicle color, membership status, and parking status. It also includes virtual functions for adding a vehicle, displaying vehicle details, calculating parking fare, and checking membership status.
- **Car** and **Bike**: Derived classes representing specific types of vehicles (car and bike), inheriting from the Vehicle class. These classes implement the virtual functions to add and display vehicle details, as well as calculate parking fare.
- **Slot**: Class representing a parking slot in the parking lot, with attributes like slot number and vacancy status. It also includes functions to park and remove vehicles from the slot.

## Usage
1. **User Registration**: Enter the number of users and provide details for each user, including name, age, gender, phone number, and initial wallet amount.
2. **Vehicle Registration**: Select a user and register a vehicle by providing details such as license ID, vehicle model, vehicle color, and membership status.
3. **Add Amount to Wallet**: Select a user and add funds to their wallet.
4. **Park Vehicle**: Select a user and park a registered vehicle. Parking charges will be deducted from the user's wallet.
5. **Display User Details**: Select a user to view their details and registered vehicles.
6. **Exit**: Exit the program.

## Limitations and Future Improvements
- Currently, the program only supports a fixed number of users and parking slots. In the future, dynamic allocation of memory and management of slots could be implemented for scalability.
- Error handling and input validation could be improved for better user experience and robustness.
- More advanced features such as real-time slot availability and automated payment systems could be added for enhanced functionality.

