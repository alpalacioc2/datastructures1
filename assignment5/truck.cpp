// ******************************************************************************************
// * File:        truck.cpp                                                                 *
// * Author:      Alejandro Palacio Caro                                                    *
// * Course:      COP3330 - Data Structures and Algorithm Analysis I                        *
// * Instructor:  Dr. David A. Gaitros                                                      *
// * Date:        July 11, 2025                                                             *
// * Description: This file implements the Truck class, which inherits from the Vehicle     *
// *              base class. It includes the constructor, accessors and mutators for       *
// *              weight and number of axles, and a customized PrintData function.          *
// ******************************************************************************************

#include "truck.h"
#include <iostream>
using namespace std;

// *******************************************************************************
// * Function: Truck (Constructor)                                               *
// * Purpose: Initializes a Truck object using Vehicle constructor               *
// *          and sets weight and number of axles                                *
// * Date: 07/11/2025                                                            *
// * Author: Alejandro Palacio Caro                                              *
// * References: Canvas chapter 15                                               *
// *******************************************************************************
Truck::Truck(string mk, string mdl, int y, char ft, char c, int mil, int w, int n)
    : Vehicle(mk, mdl, y, ft, c, mil) {
    weight = w > 0 ? w : DEFAULTWEIGHT;
    numberofaxles = n > 0 ? n : DEFAULTNUMBEROFAXLES;
}

// *****************************************************************
// * Function: setweight                                           *
// * Purpose: Sets the weight of the truck (must be > 0)           *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Truck::setweight(const int w) {
    weight = (w > 0) ? w : DEFAULTWEIGHT;
}

// *****************************************************************
// * Function: setnumberofaxles                                    *
// * Purpose: Sets the number of axles (must be > 0)               *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Truck::setnumberofaxles(const int n) {
    numberofaxles = (n > 0) ? n : DEFAULTNUMBEROFAXLES;
}

// *****************************************************************
// * Function: getweight                                           *
// * Purpose: Returns the weight of the truck                      *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
int Truck::getweight() {
    return weight;
}

// *****************************************************************
// * Function: getnumberofaxles                                    *
// * Purpose: Returns the number of axles                          *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
int Truck::getnumberofaxles() {
    return numberofaxles;
}

// *****************************************************************
// * Function: PrintData                                           *
// * Purpose: Overrides Vehicle::PrintData to display truck data   *
// *          with custom formatting including weight and axles    *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Truck::PrintData(const string s) {
    Vehicle::PrintData(s);
    cout << "Weight:" << weight << endl;
    cout << "Number of Axles: " << numberofaxles << endl;
}
