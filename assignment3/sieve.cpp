#include "sieve.h"
#include <cmath>
#include <iomanip>


// Sieve()   -  Default constructor.  
Sieve::Sieve(): lastnumber(DEFAULTMAXPRIME)                                                              // Sets the lastnumber fo the DEFAULTMAXPRIME.  
{
    bvect = new bool[lastnumber + 1];                                                        // Allocates the array bvect
    GeneratePrimes();                                                                        //call GeneratePrimes.
}

// ~Sieve() 
Sieve::~Sieve()
{
    delete[] bvect;                                                                         // / Deletes the bvect array.
}

// If below 2 sets it to DEFAULTMAXPRIME, allocates the array bvect and calls GeneratePrimes.
// For instance, if the number 70 is passed in your solution should calculate and display prime numbers up to 70 but not past it.
Sieve::Sieve(const int x)
{   
    if (x < 2)
    {
        lastnumber = DEFAULTMAXPRIME;                                                   // If x is too small, use default = 1103
    }
    else
    {    
        lastnumber = x;                                                                 // Otherwise, use the provided x
    }
    bvect = new bool[lastnumber + 1];
    GeneratePrimes();
}


void Sieve::ReSet(const int s)
{
    delete[] bvect;                                                                     // Deletes the old bvect array
    if (s < 2)
        lastnumber = DEFAULTMAXPRIME;                                                   // If s is too small, use default
    else
        lastnumber = s;                                                                 // Otherwise, use the provided s

    bvect = new bool[lastnumber + 1];                                                   // Allocate the new bvect array
    GeneratePrimes();                                                                   // Regenerate primes up to lastnumber
}

// IsPrime(const int s)
// Returns true if the number passed in by s is a prime number, otherwise returns false;
// If s is outside the range of numbers return false.
bool Sieve::IsPrime(const int s)
{
    if (s < 2 || s > lastnumber)                                                          // if it doesnt fall in the range then return false 
    {
        return false;
    }
    return bvect[s];
}


void Sieve::Print(ostream & os)                                                            // Prints every prime number from 2 up to lastnumber, separated by spaces.
{   
    for (int i = 2; i <= lastnumber; ++i)                                                  // Loop over 2 to lastnumber that are prime
    {
        if (bvect[i]) 
        {
            os << i << ' ';                                                                 // prints the prime number here
        }
    }
    os << '\n';
}

void Sieve::GeneratePrimes()
{
    // Initialize: mark 0–1 false, 2..lastnumber true
    for (int i = 0; i <= lastnumber; ++i) 
    {
        if (i < 2)
            bvect[i] = false;                                                               // 0 and 1 are non-prime
        else
            bvect[i] = true;                                                                // 2 and above might be prime numbers
    }

    // Sieve out multiples
    for (int p = 2; p * p <= lastnumber; ++p) 
    {
        if (bvect[p]) 
        {                                                                                   // only if p is still prime
            for (int m = p * p; m <= lastnumber; m += p) 
            {
                bvect[m] = false;
            }
        }
    }
}


// operator<<
// Calls the Print member function. Non-class member function.
ostream & operator<<(ostream & os, Sieve & s)
{
    s.Print(os);
    return os;
}