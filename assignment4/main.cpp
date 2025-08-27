#include <iostream>
#include "sudoku.h"
#include <string>
using namespace std;
// ***********************************************************
// * Main                                                    *
// * Test of the Sudoku Class                                *
// * Test 1:   Read in good puzzle. Print it, Checks puzzle. *
// * Test 2:   Read in Bad puzzle Print it, Checks puzzle.   *
// * Test 3:   Read in Bad puzzle Print it, Checks puzzle.   *
// * Test 4:   Try to open a non-existent file, prints out   *
// *           a message indicating it could not open it.    *
// ***********************************************************
int main() {

    Sudoku MyPuzzle1;
    Sudoku MyPuzzle2;
    Sudoku MyPuzzle3;
    Sudoku MyPuzzle4; 
    Sudoku MyPuzzle5; 
    cout << "Sudoku Puzzle Analyzer!" << std::endl;

    MyPuzzle1.Fill_Puzzle("good.dat");
    cout<<MyPuzzle1<<endl;
    if(MyPuzzle1.Check_Puzzle()) cout<<"Good Puzzle"<<endl;
    else cout<<"Bad Puzzle"<<endl;

    MyPuzzle2.Fill_Puzzle("bad1.dat");
    cout<<MyPuzzle2<<endl;
    if(MyPuzzle2.Check_Puzzle()) cout<<"Good Puzzle"<<endl;
    else cout<<"Bad Puzzle"<<endl;

    MyPuzzle3.Fill_Puzzle("bad2.dat");
    cout<<MyPuzzle3<<endl;
    if(MyPuzzle3.Check_Puzzle()) cout<<"Good Puzzle"<<endl;
    else cout<<"Bad Puzzle"<<endl;

    MyPuzzle4.Fill_Puzzle("bad3.dat");
    cout<<MyPuzzle3<<endl;
    if(MyPuzzle3.Check_Puzzle()) cout<<"Good Puzzle"<<endl;
    else cout<<"Bad Puzzle"<<endl;

    bool testopen; 
    testopen=MyPuzzle5.Fill_Puzzle("BadOpen.dat");
    if(testopen) cout<<"Error, Should not be open"<<endl; 
    else cout<<"Did not open file, invalid file"<<endl ; 
    return 0;
}
