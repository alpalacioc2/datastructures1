// *******************************************************
// * Sudoku class                                        *
// * Created by Dr. David A. Gaitros                     *
// * DATE: MAY 8TH, 2025                                 *
// * Description:   Class designed to read in a Sudoku   *
// *     puzzle and analyze it to determine if it is     *
// *     It uses a dynamically allocated 2D array even   *
// *     though the size of the puzzle never changes.    *
// * NOT FOR DISTRIBUTION                                *
// *******************************************************
//

#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int MAXROW=10;   // One more so that it is 1-9 and not 0 -8.
const int MAXCOL=10;   // One more so that it is 1-9 and not 0 - 8.
class Sudoku {
public:
    Sudoku();                               // Default Constructor
    ~Sudoku();                              // Destructor
    void Clear(); 			    // Deletes 2D array 
    bool Fill_Puzzle(const string fn);      // Propogate puzzle
    bool Check_Puzzle();                    // Valid puzzle or not
    void Print_Puzzle(ostream & os);        // Print function

private:
    bool Check_Row(const int row);
    bool Check_Col(const int col);
    bool Check_Grid(const int col);
    int * * puzzle;

};
// Non Class functions
ostream & operator << (ostream & os, Sudoku & s);   // Operator << overload

#endif //SUDOKU_SUDOKU_H
