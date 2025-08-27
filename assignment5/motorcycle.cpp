// ******************************************************************************************
// * File:        motorcycle.cpp                                                            *
// * Author:      Alejandro Palacio Caro                                                    *
// * Course:      COP3330 - Data Structures and Algorithm Analysis I                        *
// * Instructor:  Dr. David A. Gaitros                                                      *
// * Date:        July 11, 2025                                                             *
// * Description: This file implements the Motorcycle class, which inherits from the        *
// *              Vehicle base class. It includes the constructor, accessor and mutator     *
// *              for engine displacement in cubic centimeters, and a custom PrintData.     *
// ******************************************************************************************

#include "motorcycle.h"
#include <iostream>
using namespace std;

// **************************************************************************************
// * Function: Motorcycle (Constructor)                                                 *
// * Purpose: Initializes a Motorcycle using Vehicle constructor                        *
// *          and sets engine size (cc)                                                 *
// * Date: 07/11/2025                                                                   *
// * Author: Alejandro Palacio Caro                                                     *
// * References: Canvas chapter 15                                                      *
// **************************************************************************************
Motorcycle::Motorcycle(string mk, string mdl, int y, char ft, char c, int mil, int cc)
    : Vehicle(mk, mdl, y, ft, c, mil) {
    cubiccentimeters = (cc > 0) ? cc : DEFAULTCUBICCENTIMETERS;
}

// *****************************************************************
// * Function: setcubiccentimeters                                 *
// * Purpose: Sets the engine size of the motorcycle in cc         *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Motorcycle::setcubiccentimeters(const int c) {
    cubiccentimeters = (c > 0) ? c : DEFAULTCUBICCENTIMETERS;
}

// *****************************************************************
// * Function: getcubiccentimeters                                 *
// * Purpose: Returns the engine size in cubic centimeters         *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
int Motorcycle::getcubiccentimeters() {
    return cubiccentimeters;
}

// *****************************************************************
// * Function: PrintData                                           *
// * Purpose: Overrides Vehicle::PrintData to show motorcycle info *
// *          including engine size with formatted output          *
// * Date: 07/11/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Canvas chapter 15                                 *
// *****************************************************************
void Motorcycle::PrintData(const string s) {
    Vehicle::PrintData(s);
    cout << "Cubic Centimeters:" << cubiccentimeters << endl;
}
