// ******************************************************************************************
// * File:        boat.cpp                                                                  *
// * Author:      Alejandro Palacio Caro                                                    *
// * Course:      COP3330 - Data Structures and Algorithm Analysis I                        *
// * Instructor:  Dr. David A. Gaitros                                                      *
// * Date:        July 11, 2025                                                             *
// * Description: This file implements the Boat class, which inherits from the Vehicle      *
// *              base class. It includes the constructor, accessor and mutator for         *
// *              boat type, and a custom PrintData method to display full boat details.    *
// ******************************************************************************************

#include "boat.h"
#include <iostream>
using namespace std;

// **************************************************************************
// * Function: Boat (Constructor)                                           *
// * Purpose: Initializes a Boat using Vehicle constructor and              *
// *          sets the boat type string (e.g., Inboard, Sailing)            *
// * Date: 07/11/2025                                                       *
// * Author: Alejandro Palacio Caro                                         *
// * References: Canvas chapter 15                                          *
// **************************************************************************
Boat::Boat(string mk, string mdl, int y, char ft, char c, int mil, string bt)
    : Vehicle(mk, mdl, y, ft, c, mil) {
    boattype = bt;
}

// *****************************************************************
// * Function: setboattype                                         *
// * Purpose: Sets the type/category of the boat                   *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Boat::setboattype(const string bt) {
    boattype = bt;
}

// *****************************************************************
// * Function: getboattype                                         *
// * Purpose: Returns the type/category of the boat                *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
string Boat::getboattype() {
    return boattype;
}

// *****************************************************************
// * Function: PrintData                                           *
// * Purpose: Overrides Vehicle::PrintData to show full boat data  *
// *          including the boat type in formatted output          *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Boat::PrintData(const string s) {
    Vehicle::PrintData(s);
    cout << "Boat Type:" << boattype << endl;
}
