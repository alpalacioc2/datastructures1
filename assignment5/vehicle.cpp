// ******************************************************************************************
// * File:        vehicle.cpp                                                                *
// * Author:      Alejandro Palacio Caro                                                     *
// * Course:      COP3330 - Data Structures and Algorithm Analysis I                         *
// * Instructor:  Dr. David A. Gaitros                                                       *
// * Date:        July 11, 2025                                                              *
// * Description: This file implements the Vehicle base class used by Car, Truck,            *
// *              Motorcycle, and Boat. It includes field validation and a standardized       *
// *              PrintData method required for all derived classes.                         *
// ******************************************************************************************

#include "vehicle.h"
#include <iostream>
using namespace std;

// *****************************************************************
// * Function: Vehicle (Default Constructor)                       *
// * Purpose: Initializes all vehicle fields to default values     *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
Vehicle::Vehicle() {
    make = model = "";
    year = DEFAULTYEAR;
    fueltype = DEFAULTFUELTYPE;
    color = DEFAULTCOLOR;
    mileage = DEFAULTMILEAGE;
}

// *****************************************************************
// * Function: Vehicle Constructor                                 *
// * Purpose: Initializes all vehicle fields with validation       *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
Vehicle::Vehicle(string ma, string mo, int y, char ft, char c, int mi) {
    setmake(ma);
    setmodel(mo);
    setyear(y);
    setfueltype(ft);
    setcolor(c);
    setmileage(mi);
}

// Setters 
void Vehicle::setmake(const string m) {
    make = m;
}

void Vehicle::setmodel(const string m) {
    model = m;
}

void Vehicle::setyear(const int y) {
    year = (y >= DEFAULTYEAR) ? y : DEFAULTYEAR;
}

void Vehicle::setfueltype(const char f) {
    switch (f) {
        case 'E': case 'G': case 'D': case 'W': case 'P':
            fueltype = f; break;
        default:
            fueltype = DEFAULTFUELTYPE;
    }
}

void Vehicle::setcolor(const char c) {
    switch (c) {
        case 'R': case 'O': case 'Y': case 'G': case 'B': case 'I': case 'V': case 'E':
            color = c; break;
        default:
            color = DEFAULTCOLOR;
    }
}

void Vehicle::setmileage(const int m) {
    mileage = (m > 0) ? m : DEFAULTMILEAGE;
}

// Getters
string Vehicle::getmake() {
    return make;
}

string Vehicle::getmodel() {
    return model;
}

int Vehicle::getyear() {
    return year;
}

int Vehicle::getmileage() {
    return mileage;
}

string Vehicle::getfueltype() {
    switch (fueltype) {
        case 'E': return "Electric/Solar";
        case 'G': return "Gas";
        case 'D': return "Diesel";
        case 'W': return "Wind";
        case 'P': return "Pedal";
        default:  return "Unknown";
    }
}

string Vehicle::getcolor() {
    switch (color) {
        case 'R': return "Red";
        case 'O': return "Orange";
        case 'Y': return "Yellow";
        case 'G': return "Green";
        case 'B': return "Blue";
        case 'I': return "Indigo";
        case 'V': return "Violet";
        case 'E': return "Ebony";
        default:  return "Unknown";
    }
}

// *****************************************************************
// * Function: PrintData                                           *
// * Purpose: Prints formatted vehicle information with labels     *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Vehicle::PrintData(const string s) {
    cout << "******** " << s << " *******" << endl;
    cout << "Model:  " << getmodel() << endl;
    cout << "Make :  " << getmake() << endl;
    cout << "Year :  " << getyear() << endl;
    cout << "Color:  " << getcolor() << endl;
    cout << "Fuel Type: " << getfueltype() << endl;
    cout << "Mileage: " << getmileage() << endl;
}
