//
// Created by David Gaitros on 8/11/24.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

struct date_struct
{
    int month;    // 1-12
    int day;      // validate date day with month and year
    int year;     // greater than 1900
};
const string DEFAULTSTUDENTID="000000000";
const date_struct DEFAULTDOB={1,1,1900};
const string DEFAULTHOMEPHONE="5555555555";
const string DEFAULTMAJOR="Math";
const int    MINIMUMGPA=0; 
const int    MAXIMUMGPA=4.0; 
class Student {
public:
    Student(string fn, string ln, char mi, string id, float g, string ma, int m, int d, int y, string hp);
    Student(); //Default Constructor 
    void Setlast_name(const string ln);
    void Setfirst_name(const string fn);
    void Setmi(const char m);
    void Setstudent_id(const string si);     // 9 digits, allow leading zeros , default all zeros
    void Setgpa(const float g);
    void Setmajor(const string m);
    void Setdate_of_birth(const int m, const int d, const int y);
    void Sethome_phone(const string h);
    string Getlast_name();
    string Getfirst_name();
    char Getmi();
    string Getstudent_id();
    float Getgpa();
    string Getmajor();
    string Getdate_of_birth();    // formatted dd/mm/yyyy
    string Gethome_phone();        // formated (999) 999-9999
    void PrintStudent();

private:
    bool Valid_Date(const int m, const int d, const int y);
    bool Valid_Phone(const string p);
    bool Valid_Major(const string m);
    string last_name;
    string first_name;
    char mi;                   // Single character, blank is optional
    string student_id;         // exactly nine digits
    float gpa;                 // 0.0 to 4.0
    string major;              // Must be validated
    date_struct date_of_birth; // Must be a valid date.
    string home_phone;          // US Phone 10 digits

};


#endif //ASSIGNMENT2FALL2024_STUDENT_H
