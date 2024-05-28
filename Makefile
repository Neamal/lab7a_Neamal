# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
BINARIES = lab7atest

all: ${BINARIES}

lab7atest: lab7atest.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./lab7atest

clean:
	/bin/rm -f ${BINARIES} *.o