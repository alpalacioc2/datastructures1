// File:        student.cpp
// Author:      Alejandro Palacio Caro
// Instructor:  Dr. David A. Gaitros
// Course:      COP3330 - Data Structures and Algorithm Analysis I
// Date:        May 21, 2025
// Description: Implementation of the Student class including constructors,
//              mutator and accessor methods, and data validation logic.

#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

// Constant default values
//const string DEFAULTSTUDENTID = "000000000";
//const string DEFAULTMAJOR = "Math";
//const float MINIMUMGPA = 0.0;
//const string DEFAULTHOMEPHONE = "5555555555";
//const int DEFAULT_MONTH = 1;
//const int DEFAULT_DAY = 1;
//const int DEFAULT_YEAR = 1900;

// *****************************************************************
// * Function: Student (Default Constructor)                       *
// * Purpose: Initializes all student fields to default values     *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
Student::Student() {
    Setfirst_name("");
    Setlast_name("");
    Setmi(' ');
    Setstudent_id(DEFAULTSTUDENTID);
    Setgpa(MINIMUMGPA);
    Setmajor(DEFAULTMAJOR);
    date_of_birth = DEFAULTDOB;   
    Sethome_phone(DEFAULTHOMEPHONE);
}


// *****************************************************************
// * Function: Student (Parameterized Constructor)                 *
// * Purpose: Initializes student fields with provided values      *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
Student::Student(string fn, string ln, char m, string id, float g, string ma, int mm, int dd, int yy, string hp) 
{
    Setfirst_name(fn);
    Setlast_name(ln);
    Setmi(m);
    Setstudent_id(id);
    Setgpa(g);
    Setmajor(ma);
    Setdate_of_birth(mm, dd, yy);
    Sethome_phone(hp);
}

// *****************************************************************
// * Function: Setfirst_name                                       *
// * Purpose: Sets the student's first name                        *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Setfirst_name(const string fn)
{
    first_name = fn;
}

// *****************************************************************
// * Function: Setlast_name                                        *
// * Purpose: Sets the student's last name                         *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Setlast_name(const string ln)
{
    last_name = ln;
}

// *****************************************************************
// * Function: Setmi                                               *
// * Purpose: Sets middle initial if alphabetic; else blank        *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Setmi(const char m)
{   
    // if character is alphabetic gets stored otherwise is set to blank
    if (isalpha(m)) 
    {
        mi = m;
    } 
    else 
    {
    mi = ' ';
    }
}

// *****************************************************************
// * Function: Setstudent_id                                       *
// * Purpose: Validates and sets a 9-digit student ID              *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Setstudent_id(const string si)
{
    bool valid = (si.length() == 9);
    for (int i = 0; i < si.length() && valid; i++)
    {
        if (!isdigit(si[i]))
        {
            valid = false;
        }
    
    }
    if ( valid )
    {
        student_id =  si;
    }
    else
    {
        student_id = DEFAULTSTUDENTID;
    }
}

// *****************************************************************
// * Function: Setgpa                                              *
// * Purpose: Validates and sets GPA between 0.0 and 4.0           *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Setgpa(const float g)
{
    if (g >= 0.0 && g <= 4.0)
    {
        gpa = g;
    }
    else
    {
        gpa = MINIMUMGPA;
    }
}

// *****************************************************************
// * Function: Setmajor                                            *
// * Purpose: Validates and sets the student major                 *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Setmajor(const string m)
{
    if (Valid_Major(m))
    {
        major = m;
    }
    else
    {
        major = DEFAULTMAJOR;
    }
}

// *****************************************************************
// * Function: Setdate_of_birth                                    *
// * Purpose: Validates and sets date of birth                     *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Setdate_of_birth(const int m, const int d, const int y)
{
    if (Valid_Date(m , d , y))
    {
        date_of_birth.month = m;
        date_of_birth.day = d;
        date_of_birth.year = y;
    }
    else
    {
        date_of_birth = DEFAULTDOB;    
    }
}

// *****************************************************************
// * Function: Sethome_phone                                       *
// * Purpose: Validates and sets the student's phone number        *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::Sethome_phone(const string h)
{
    if (Valid_Phone(h))
    {
        home_phone = h;
    }
    else
    {
        home_phone = DEFAULTHOMEPHONE;
    }
}

// *****************************************************************
// * Function: Getfirst_name                                       *
// * Purpose: Returns the student's first name                     *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
string Student::Getfirst_name()
{
    return first_name;
}

// *****************************************************************
// * Function: Getlast_name                                        *
// * Purpose: Returns the student's last name                      *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
string Student::Getlast_name()
{
    return last_name;
}

// *****************************************************************
// * Function: Getmi                                               *
// * Purpose: Returns the student's middle initial                 *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
char Student::Getmi()
{
    return mi;
}

// *****************************************************************
// * Function: Getstudent_id                                       *
// * Purpose: Returns the student's ID                             *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
string Student::Getstudent_id()
{
    return student_id;
}

// *****************************************************************
// * Function: Getgpa                                              *
// * Purpose: Returns the student's GPA                            *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
float Student::Getgpa()
{
    return gpa;
}

// *****************************************************************
// * Function: Getmajor                                            *
// * Purpose: Returns the student's major                          *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
string Student::Getmajor()
{
    return major;
}

// *****************************************************************
// * Function: Getdate_of_birth                                    *
// * Purpose: Returns the student's date of birth in mm/dd/yyyy    *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
string Student::Getdate_of_birth()
{
    return to_string(date_of_birth.month) + "/" + to_string(date_of_birth.day) + "/" + to_string(date_of_birth.year);
}

// *****************************************************************
// * Function: Gethome_phone                                       *
// * Purpose: Returns phone number in (999) 999-9999 format        *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
string Student::Gethome_phone()
{
    return "(" + home_phone.substr(0, 3) + ") " + home_phone.substr(3, 3) + "-" + home_phone.substr(6, 4);
}

// *****************************************************************
// * Function: PrintStudent                                        *
// * Purpose: Prints all student details in formatted output       *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
void Student::PrintStudent()
{
    cout << fixed << setprecision(2);
    cout << Getfirst_name() << " " << Getmi() << ". " << Getlast_name() << endl;
    cout << "Major: " << Getmajor() << "  GPA: " << Getgpa() << " Date of Birth: " << Getdate_of_birth() << endl;
    cout << "Home Phone is: " << Gethome_phone() << endl << endl;

}

// *****************************************************************
// * Function: Valid_Date                                          *
// * Purpose: Validates if the date is in a valid format and range *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: Leap year rules                                   *
// *****************************************************************
bool Student::Valid_Date(const int m, const int d, const int y) 
    {
    if (y < 1900) 
    {
        return false;
    }
    if (m < 1 || m > 12) 
    {
        return false;
    }
    if (d < 1) 
    {
        return false;
    }

    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Leap year adjustment
    bool is_leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    if (is_leap && m == 2) days_in_month[1] = 29;

    return d <= days_in_month[m - 1];
}

// *****************************************************************
// * Function: Valid_Phone                                         *
// * Purpose: Validates a 10-digit phone number not starting with 0*
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
bool Student::Valid_Phone(const string p) {
    // Must be 10 digits and not start with '0'
    if (p.length() != 10 || p[0] == '0') {
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        if (!isdigit(p[i])) {
            return false;
        }
    }

    return true;
}

// *****************************************************************
// * Function: Valid_Major                                         *
// * Purpose: Validates if the major is one of the allowed values  *
// * Date: 05/21/2025                                              *
// * Author: Alejandro Palacio Caro                                *
// * References: N/A                                               *
// *****************************************************************
bool Student::Valid_Major(const string m) {
    // Check if major is one of the allowed values
    return m == "CompSci" || m == "Math" || m == "EE" || m == "Bio" || m == "Chem";
}
