# Makefile for lab00, Mitchell Koerner, CS32, S19

CXX=clang++
# CXX=G++
CVER=c++14
CXXFLAGS=-std=c++14
DEPENDENCIES=Coords.o Entity.o Creature.o Arena.o helper_functions.o\
DerivedCreatures1.o

main: main.o ${DEPENDENCIES}
	${CXX} $^ -o $@ 

testCoords: testCoords.o ${DEPENDENCIES}
	${CXX} $^ -o $@ 

testCreature: testCreature.o ${DEPENDENCIES}
	${CXX} $^ -o $@ 

testSingleCreature: testSingleCreature.o ${DEPENDENCIES}
	${CXX} $^ -o $@ 

randTest: randTest.o Coords.o
	${CXX} $^ -o $@ 



clean:
	/bin/rm -f *.o main testCoords testCreature testSingleCreature randTest
	/bin/rm -rf main.dSYM