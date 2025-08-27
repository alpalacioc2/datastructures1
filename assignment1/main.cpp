

// File:        assignment1.cpp
// Author:      Alejandro Palacio Caro
// Instructor:  Dr. David A. Gaitros
// Course:      COP3330 - Data structures and algorithm Analysis I
// Date:        May 14, 2025
// Description: 

//All Includes 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

// Constant Variables with specific range parameters per professor
const int MIN_COUNT = 3;
const int MAX_COUNT = 7;
const int MIN_RANGE = 45;
const int MAX_RANGE = 70;
const int MAX_TICKET_COUNT = 100;

// Prototype Functions
int getNumberOfBalls();
int getMaxRange();
int getNumberOfTickets();
vector <int> generateTicket(int numBalls, int maxRange);//creates and returns a single lottery ticket represented as a vector of random non repeated numbers.


// *****************************************************************
// * Main function that calls helper functions to query the user   *
// * and generate lottery tickets with unique numbers.             *
// * Date: 05/14/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
int main() {
    srand(time(0)); // This is the Seed for the random number generator 

    // store and get user inputs
    int numBalls = getNumberOfBalls();
    int maxRange = getMaxRange();
    int numTickets = getNumberOfTickets();

    // Displaying comments for user
    cout << "\nYou will select " << numBalls << " numbers\n";
    cout << "The numbers will range from 1 to " << maxRange << "\n";
    cout << "YOUR LOTTERY SELECTIONS ARE:\n\n";

    // Print the result of tickets
    for (int i = 0; i < numTickets; ++i) {
        vector<int> ticket = generateTicket(numBalls, maxRange);
        for (int num : ticket) {
            cout << setw(3) << num;
        }
        cout << endl;
    }

    cout << "\nGOOD LUCK\n";
    return 0;
}

// *****************************************************************
// * Collects the user for the number of balls per ticket,         *
// * ensuring input is between 3 and 7 inclusive.                  *
// * Date: 05/14/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Assignment specification                          *
// *****************************************************************
int getNumberOfBalls() {
    int balls;
    do {
        cout << "Enter in the number of balls or numbers you wish to pick from. The number must be between " << MIN_COUNT << " and " << MAX_COUNT << ": ";
        cin >> balls;
        if (balls < MIN_COUNT || balls > MAX_COUNT) {
            cout << "Invalid entry, please enter a number between " << MIN_COUNT << " and " << MAX_COUNT << " inclusive: ";
            cin >> balls;
        }
    } while (balls < MIN_COUNT || balls > MAX_COUNT);
    return balls;
}


// *****************************************************************
// * Collects the user input for the largest lottery number        *
// * ensuring input is between 45 and 70 inclusive.                *
// * Date: 05/14/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Assignment specification                          *
// *****************************************************************
int getMaxRange() {
    int range;
    do {
        cout << "Enter in the largest number in the lottery. The number must be between " << MIN_RANGE << " - " << MAX_RANGE << ": ";
        cin >> range;
        while (range < MIN_RANGE || range > MAX_RANGE) {
            cout << "Invalid entry, please enter a number between " << MIN_RANGE << " and " << MAX_RANGE << " inclusive: ";
            cin >> range;
        }
    } while (range < MIN_RANGE || range > MAX_RANGE);
    return range;
}


// *****************************************************************
// * Prompts the user for the number of tickets to generate,       *
// * ensuring input is between 1 and 100 inclusive.                *
// * Date: 05/14/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Assignment specification                          *
// *****************************************************************
int getNumberOfTickets() {
    int tickets;
    do {
        cout << "Enter the number of tickets 1 - " << MAX_TICKET_COUNT << " inclusive: ";
        cin >> tickets;
        while (tickets < 1 || tickets > MAX_TICKET_COUNT) {
            cout << "Invalid entry, please enter a number between 1 and " << MAX_TICKET_COUNT << " inclusive: ";
            cin >> tickets;
        }
    } while (tickets < 1 || tickets > MAX_TICKET_COUNT);
    return tickets;
}


// *****************************************************************
// * Generates a single lottery ticket with a specified number     *
// * of unique random numbers in the range 1 to maxRange.          *
// * The numbers are sorted before returning.                      *
// * Date: 05/14/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Algorithm based on shuffling and slicing method.  *
// *****************************************************************
vector<int> generateTicket(int numBalls, int maxRange) {
    vector<int> pool;
    for (int i = 1; i <= maxRange; ++i) {
        pool.push_back(i);
    }

    random_shuffle(pool.begin(), pool.end());

    vector<int> ticket(pool.begin(), pool.begin() + numBalls);
    sort(ticket.begin(), ticket.end());
    return ticket;
}
