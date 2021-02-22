CC = g++
CFLAGS = -g -w -Wall

SchooolManagement: SchoolManagement.o checker.o data.o delemitMethods.o functions.o userInterface.o
	$(CC) $(CFLAGS) -o SchoolManagement SchoolManagement.o checker.o data.o delemitMethods.o functions.o userInterface.o

checker.o: checkers.h checker.cpp
	$(CC) $(CFLAGS) -c checker.cpp

data.o: data.h data.cpp
	$(CC) $(CFLAGS) -c data.cpp

functions.o: functions.h functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp

delemitMethods.o: delemitMethods.cpp
	$(CC) $(CFLAGS) -c delemitMethods.cpp

userInterface.o: userInterface.h userInterface.cpp
	$(CC) $(CFLAGS) -c userInterface.cpp

clean:
	rm -f core *.o SchoolManagement
