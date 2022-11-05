CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = src/main.o src/Automata.o src/Alphabet.o src/Chain.o src/State.o src/Transition.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p06_automata_simulator ${OBJS}

clean: 
	rm -rf src/*.o p06_automata_simulator