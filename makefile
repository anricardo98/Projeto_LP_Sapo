#Makefile for "sapo_corrida" C++ application
#Created by Andre 04/06/2018

PROG = sapo_corrida
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o sapo.o pista.o corrida.o 

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	 $(CC) $(CPPFLAGS) -c main.cpp

sapo.o: sapo.hpp
	$(CC) $(CPPFLAGS) -c sapo.cpp

pista.o: pista.hpp
	$(CC) $(CPPFLAGS) -c pista.cpp

corrida.o: corrida.hpp
	$(CC) $(CPPFLAGS) -c corrida.cpp

clean:
	rm -f *.o