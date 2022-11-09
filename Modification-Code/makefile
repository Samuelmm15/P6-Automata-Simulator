CC=g++
CXXFLAGS=-g -std=c++14

OBJS = src/main.o src/automata.o src/alphabet.o src/chain.o src/state.o src/transition.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p06_automata_simulator ${OBJS}

clean: 
	rm -rf src/*.o p06_automata_simulator