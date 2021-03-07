CC = g++ -std=c++14
CFLAGS = -g -w -Wall
 
SchooolManagement: SchoolManagement.o checker.o data.o delimitMethods.o userInterface.o logs.o messages.o
	$(CC) $(CFLAGS) -o SchoolManagement SchoolManagement.o checker.o data.o delimitMethods.o userInterface.o logs.o messages.o
 
checker.o: checkers.h checker.cpp
	$(CC) $(CFLAGS) -c checker.cpp
 
data.o: data.h data.cpp
	$(CC) $(CFLAGS) -c data.cpp
 
delimitMethods.o: delimitMethods.cpp
	$(CC) $(CFLAGS) -c delimitMethods.cpp
 
userInterface.o: userInterface.h userInterface.cpp
	$(CC) $(CFLAGS) -c userInterface.cpp
 
logs.o: logs.cpp
	$(CC) $(CFLAGS) -c logs.cpp

messages.o: messages.h messages.cpp
	$(CC) $(CFLAGS) -c messages.cpp

clean:
	rm -f core *.o SchoolManagement