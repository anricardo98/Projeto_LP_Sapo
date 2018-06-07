#Makefile for "sapo_corrida" C++ application
#Created by Andre 04/06/2018

PROG = sapo_corrida
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic
OBJS = main.o sapo.o pista.o corrida.o 

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp

sapo.o: include/sapo.hpp
	$(CC) $(CPPFLAGS) -c src/sapo.cpp

pista.o: include/pista.hpp
	$(CC) $(CPPFLAGS) -c src/pista.cpp

corrida.o: include/corrida.hpp
	$(CC) $(CPPFLAGS) -c src/corrida.cpp

clean:
	rm -f *.o