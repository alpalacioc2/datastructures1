# *****************************************************************
# * File:        makefile                                         *
# * Author:      Alejandro Palacio Caro                           *
# * Instructor:  Dr. David A. Gaitros                             *
# * Course:      COP3330 - Data Structures and Algorithm Analysis I *
# * Date:        May 21, 2025                                     *
# * Description: Compilation instructions for the Student class   *
# *              and main driver program using g++ and C++11.     *
# *****************************************************************
main: main.o student.o
	g++ -std=c++11 -o main main.o student.o

main.o: main.cpp student.h
	g++ -std=c++11 -c main.cpp

student.o: student.cpp student.h
	g++ -std=c++11 -c student.cpp

clean:
	rm -f *.o main

