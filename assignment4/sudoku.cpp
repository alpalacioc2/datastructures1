// *******************************************************************************************
// * File:        sudoku.cpp                                                                 *
// * Author:      Alejandro Palacio Caro                                                     *
// * Date:        06/27/2025                                                                 *
// * Course:      C++ Programming                                                            *
// * Assignment:  Project #4 – Sudoku Puzzle Analyzer                                        *
// * Description: This file implements the Sudoku class which dynamically allocates a 9x9    *
// *              puzzle grid, reads data from a file, checks the validity of the puzzle     *
// *              according to Sudoku rules, and prints the formatted puzzle to an output    *
// *              stream. It also includes an overloaded << operator for clean output.       *
// * References: Chapter 11 (Class design, operator overloads) and Chapter 12 (Streams, I/O) *
// *******************************************************************************************

#include "sudoku.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// *****************************************************************
// * Function: Sudoku (Default Constructor)                        *
// * Purpose: Allocates a 9x9 2D puzzle array and initializes all  *
// *          elements to 0 directly                               *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Video lecture on dynamic 2D arrays                *
// *****************************************************************
Sudoku::Sudoku() {
  puzzle = new int *[MAXROW];
  for (int i = 0; i < MAXROW; ++i) {
    puzzle[i] = new int[MAXCOL];
    for (int j = 0; j < MAXCOL; ++j) {
      puzzle[i][j] = 0;
    }
  }
}

// *****************************************************************
// * Function: ~Sudoku (Destructor)                                *
// * Purpose: Frees all dynamically allocated memory by calling    *
// *          Clear()                                              *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
Sudoku::~Sudoku() { 
  Clear();
}

// *****************************************************************
// * Function: Clear                                               *
// * Purpose: Deletes the dynamically allocated puzzle array and   *
// *          resets the pointer to nullptr                        *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Sudoku::Clear() {
  if (puzzle != nullptr) {
    for (int i = 0; i < MAXROW; ++i) {
      delete[] puzzle[i];
    }
    delete[] puzzle;
    puzzle = nullptr;
  }
}

// *****************************************************************
// * Function: Fill_Puzzle                                         *
// * Purpose: Reads puzzle values from a given file and fills the  *
// *          puzzle array. Validates input values (1–9)           *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
bool Sudoku::Fill_Puzzle(const string fn) {
  ifstream file(fn);
  if (!file)
    return false;

  for (int i = 0; i < MAXROW - 1; ++i) {
    for (int j = 0; j < MAXCOL - 1; ++j) {
      file >> puzzle[i][j];
      if (file.fail() || puzzle[i][j] < 1 || puzzle[i][j] > 9)
        return false;
    }
  }
  return true;
}

// *****************************************************************
// * Function: Print_Puzzle                                        *
// * Purpose: Outputs the 9x9 puzzle array in a formatted grid     *
// *          to the provided output stream                        *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Sudoku::Print_Puzzle(ostream &os) {
  for (int i = 0; i < MAXROW - 1; ++i) {
    os << "-------------------" << endl;
    os << "|";
    for (int j = 0; j < MAXCOL - 1; ++j) {
      os << puzzle[i][j] << "|";
    }
    os << endl;
  }
  os << "-------------------" << endl;
}

// *****************************************************************
// * Function: Check_Puzzle                                        *
// * Purpose: Validates the entire puzzle by checking all rows,    *
// *          columns, and 3x3 grids for unique digits             *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
bool Sudoku::Check_Puzzle() {
  for (int i = 0; i < MAXROW - 1; ++i) {
    if (!Check_Row(i) || !Check_Col(i) || !Check_Grid(i))
      return false;
  }
  return true;
}

// *****************************************************************
// * Function: Check_Row                                           *
// * Purpose: Checks that a single row contains digits 1–9         *
// *          without duplicates                                   *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
bool Sudoku::Check_Row(const int row) {
  bool seen[10] = {false};
  for (int j = 0; j < MAXCOL - 1; ++j) {
    int val = puzzle[row][j];
    if (seen[val])
      return false;
    seen[val] = true;
  }
  return true;
}

// *****************************************************************
// * Function: Check_Col                                           *
// * Purpose: Checks that a single column contains digits 1–9      *
// *          without duplicates                                   *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
bool Sudoku::Check_Col(const int col) {
  bool seen[10] = {false};
  for (int i = 0; i < MAXROW - 1; ++i) {
    int val = puzzle[i][col];
    if (seen[val])
      return false;
    seen[val] = true;
  }
  return true;
}

// *****************************************************************
// * Function: Check_Grid                                          *
// * Purpose: Validates a 3x3 sub-grid to ensure it contains       *
// *          digits 1–9 with no duplicates                        *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
bool Sudoku::Check_Grid(const int index) {
  bool seen[10] = {false};
  int startRow = (index / 3) * 3;
  int startCol = (index % 3) * 3;

  for (int i = startRow; i < startRow + 3; ++i) {
    for (int j = startCol; j < startCol + 3; ++j) {
      int val = puzzle[i][j];
      if (seen[val])
        return false;
      seen[val] = true;
    }
  }
  return true;
}

// *****************************************************************
// * Function: operator<<                                          *
// * Purpose: Overloads the << operator to output the Sudoku       *
// *          puzzle using Print_Puzzle                            *
// * Date: 06/27/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Chapter 11                                        *
// *****************************************************************
ostream &operator<<(ostream &os, Sudoku &s) {
  s.Print_Puzzle(os);
  return os;
}
