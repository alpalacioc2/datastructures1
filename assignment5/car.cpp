// ******************************************************************************************
// * File:        car.cpp                                                                   *
// * Author:      Alejandro Palacio Caro                                                    *
// * Course:      COP3330 - Data Structures and Algorithm Analysis I                        *
// * Instructor:  Dr. David A. Gaitros                                                      *
// * Date:        July 11, 2025                                                             *
// * Description: This file implements the Car class, which inherits from the Vehicle base  *
// *              class. It includes the constructor, accessor and mutator for car type,    *
// *              and a customized PrintData method to display the full state of a Car.     *
// ******************************************************************************************

#include "car.h"
#include <iostream>
using namespace std;

// *****************************************************************
// * Function: Car (Constructor)                                   *
// * Purpose: Initializes a Car object using Vehicle constructor   *
// *          and sets the car type string                         *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
Car::Car(string mk, string mdl, int y, char ft, char c, int mil, string ct)
    : Vehicle(mk, mdl, y, ft, c, mil) {
    cartype = ct;
}

// *****************************************************************
// * Function: setcartype                                          *
// * Purpose: Sets the type/category of the car (e.g., Sedan)      *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Car::setcartype(const string c) {
    cartype = c;
}

// *****************************************************************
// * Function: getcartype                                          *
// * Purpose: Returns the current car type string                  *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
string Car::getcartype() {
    return cartype;
}

// *****************************************************************
// * Function: PrintData                                           *
// * Purpose: Overrides Vehicle::PrintData to show full car data   *
// *          including car type                                   *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Car::PrintData(const string s) {
    Vehicle::PrintData(s);
    cout << "Car Type:" << cartype << endl;
}
