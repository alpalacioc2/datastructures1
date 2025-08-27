#include <iostream>
#include <string>
#include "student.h"
const int MAXARRAYSIZE=5;
using namespace std;

int main() {
    Student MyStudent[MAXARRAYSIZE];
    Student 
    OneStudent("David","Gaitros",'A',"555555555",4.0,"CompSci",2,18,1955,"5552490001");
    cout<<" Test of the Student Class COP3330 Programming Assignment"<<endl; 
    cout<<" You will enter data for "<<MAXARRAYSIZE<<" student records"<<endl;
    for (int index=0; index<MAXARRAYSIZE; index++)
    {   string mystring;
      	int    myintmonth;
 	int    myintday;
	int    myintyear; ; 
      	float  myfloat;
        char   mychar;  
      	cout<<"For Record number "<<index+1<<endl; 
      	cout<<"Enter  First Name, MI, Lastname, ID, GPA, Major DOB, and Phone"<<endl; 
      	cin>>mystring;   MyStudent[index].Setfirst_name(mystring);	
      	cin>>mychar;   MyStudent[index].Setmi(mychar);
      	cin>>mystring;   MyStudent[index].Setlast_name(mystring);	
      	cin>>mystring;   MyStudent[index].Setstudent_id(mystring);
      	cin>>myfloat;   MyStudent[index].Setgpa(myfloat);
      	cin>>mystring;   MyStudent[index].Setmajor(mystring);
	cin>>myintmonth; 
	cin>>myintday;
	cin>>myintyear; 
        MyStudent[index].Setdate_of_birth(myintmonth,myintday,myintyear); 
	cin>>mystring; MyStudent[index].Sethome_phone(mystring);

	
    } 
	for (int index=0; index<MAXARRAYSIZE; index++)
		MyStudent[index].PrintStudent(); 
        cout<<"Print of single object with 10 parameters"<<endl; 
        OneStudent.PrintStudent(); 
    return 0;
}
