# *****************************************************************
# * File:        makefile                                         *
# * Author:      Alejandro Palacio Caro                           *
# * Instructor:  Dr. David A. Gaitros                             *
# * Course:      COP3330 - Data Structures and Algorithm Analysis I *
# * Date:        July 11, 2025                                    *
# * Description: Compilation instructions for the Vehicle class   *
# *              hierarchy and main driver using g++ and C++11.   *
# *****************************************************************

main: main.o vehicle.o car.o truck.o motorcycle.o boat.o
	g++ -std=c++11 -o main main.o vehicle.o car.o truck.o motorcycle.o boat.o

main.o: main.cpp car.h truck.h motorcycle.h boat.h
	g++ -std=c++11 -c main.cpp

vehicle.o: vehicle.cpp vehicle.h
	g++ -std=c++11 -c vehicle.cpp

car.o: car.cpp car.h vehicle.h
	g++ -std=c++11 -c car.cpp

truck.o: truck.cpp truck.h vehicle.h
	g++ -std=c++11 -c truck.cpp

motorcycle.o: motorcycle.cpp motorcycle.h vehicle.h
	g++ -std=c++11 -c motorcycle.cpp

boat.o: boat.cpp boat.h vehicle.h
	g++ -std=c++11 -c boat.cpp

clean:
	rm -f *.o main

