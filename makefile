CC = gcc

CPPFLAGS = -g -Wall -Wextra
LDFLAGS  = -g -lstdc++ -lm

.PHONEY: all clean


main: main.o StatisticalRequest.o Request.o 
	$(CC) $(LDFLAGS) -o main main.o StatisticalRequest.o Request.o 

main.o: main.cpp StatisticalRequest.hpp
	$(CC) $(CPPFLAGS) -c main.cpp StatisticalRequest.cpp

StatisticalRequest.o: StatisticalRequest.cpp StatisticalRequest.hpp Request.hpp
	$(CC) $(CPPFLAGS) -c StatisticalRequest.cpp Request.cpp

Request.o: Request.cpp Request.hpp
	$(CC) $(CPPFLAGS) -c Request.cpp


all: main

clean: 
	-rm -f *.o
