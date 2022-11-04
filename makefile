CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p06_automata_simulator ${OBJS}

clean: 
	rm -rf *.o p06_automata_simulator