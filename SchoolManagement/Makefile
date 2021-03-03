CC = g++ -std=c++14
CFLAGS = -g -w -Wall
 
SchooolManagement: SchoolManagement.o checker.o data.o delimitMethods.o functions.o userInterface.o logs.o
	$(CC) $(CFLAGS) -o SchoolManagement SchoolManagement.o checker.o data.o delimitMethods.o functions.o userInterface.o logs.o
 
checker.o: checkers.h checker.cpp
	$(CC) $(CFLAGS) -c checker.cpp
 
data.o: data.h data.cpp
	$(CC) $(CFLAGS) -c data.cpp
 
functions.o: functions.h functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp
 
delimitMethods.o: delimitMethods.cpp
	$(CC) $(CFLAGS) -c delimitMethods.cpp
 
userInterface.o: userInterface.h userInterface.cpp
	$(CC) $(CFLAGS) -c userInterface.cpp
 
logs.o: logs.cpp
	$(CC) $(CFLAGS) -c logs.cpp

clean:
	rm -f core *.o SchoolManagement