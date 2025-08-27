#include <iostream>
#include "sieve.h"
using namespace std;
void SetNumbers(Sieve & m);
void CheckNumber(Sieve & m);
void ResetHighest(Sieve & m);
void PrintMenu()
{
    cout <<endl;
    cout <<"PRIME TIME NUMBER GENERATOR     "<<endl;
    cout <<"________________________________"<<endl;
    cout <<" S -> Set Highest Prime Number  "<<endl;
    cout <<" C -> Check if a number is prime"<<endl;
    cout <<" P -> Print the current list    "<<endl;
    cout <<" E -> Exit System               "<<endl;
    cout <<"________________________________"<<endl;
    cout <<"Enter option: ";
}
int main() {
    Sieve mynumbers;
    char option;
    PrintMenu();
    cin>>option;
    while(option != 'E' ||option !='e')
    {
        {
            switch (option) {
                case 'S':
                case 's':
                    SetNumbers(mynumbers);
                    break;
                case 'C':
                case 'c':
                    CheckNumber(mynumbers);
                    break;
                case 'P':
                case 'p':
                    cout<<mynumbers<<endl;  break;
                case 'e':
                case 'E': return 0;
                default:
                    cout << "Invalid Option" << endl;


            }
            PrintMenu();
            cin>>option;
        }
    }
    std::cout << "Good Bye" << std::endl;
    return 0;
}
// *****************************************************************
// * Name: SetNumbers                                              * 
// * Description: Accepts as input, a value from standard input    *
// *     and passes the value to the member function ReSet();      * 
// * Parameters:  Sieve object by reference                        * 
// * Date: January 8th, 2024                                       * 
// * Author: Dr. David A. Gaitros                                  * 
// * The following code is for classroom use only and not to be    *
// *    distributed.                                               *
// *****************************************************************
void SetNumbers(Sieve & m)
{
    int number;
    cout<<"Enter in the highest prime number or near it: ";
    cin>>number;
    m.ReSet(number);
}
// *****************************************************************
// * Name: Checknumber                                             * 
// * Description:  Accepts as an input an integer from standard    *
// *    input and calls the member function IsPrime() to determine *
// *    if the number passed in was indeed a prime number within   *
// *    the current list.  IF a number is passed in that exceeds   *
// *    the last number, a value of false will be returned         *
// *    regardless of whether it is prime or not.                  * 
// * Parameters: Sieve object by reference                         * 
// * Date: January 8th, 2024                                       *
// * Author: Dr. David A. Gaitros                                  *
// * The following code is for classroom use only and not to be    *
// *    distributed.                                               *
// *****************************************************************

void CheckNumber(Sieve & m)
{   int number;
    cout<<"Enter the number you want to check: ";
    cin >>number;
    if(m.IsPrime(number)) cout<<number<<" is Prime ";
    else cout<<number<<" Is Not Prime"<<endl;
}
// *****************************************************************
// * Name: ResetHighest                                            * 
// * Description: Asks the user to input a new highest number and  * 
// *      checks to see if it higher than 2.  The number is then   *
// *      passed to the member function ReSet() to set the         *
// *      highest value to be checked for prime.                   * 
// * Parameters: Sieve object by reference                         * 
// * Date: January 8th, 2024                                       * 
// * Author: Dr. David A. Gaitros                                  *
// * The following code is for classroom use only and not to be    *
// *    distributed.                                               *
// *****************************************************************

void ResetHighest(Sieve & m) {
    int number;
    cout << "Enter a number higher than 2: ";
    cin >> number;
    while (number <= 2) {
        cout << "Invalid number - re-enter: ";
        cin >> number;
    }
    m.ReSet(number);
}
