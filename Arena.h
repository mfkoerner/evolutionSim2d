// Arena.h

/*
-- Class: Arena --
    -Arena is a high level class that combines creatures and food to simulate
    evolution
    -comes with a size (x and y) and a file to write output to (outFilePath)

Constructors
    -SquareArena(float xSize, float ySize, std::string outFilePath)
        -declare a SquareArena of size xSize, ySize which writes to outFilePath

    -SquareArena()
        -declare a SquareArena of size 20 by 20, with outFilePath of "out.txt"

    -SquareArena(SquareArena &orig)
        -copies one SquareArena to another, not as well bug tested

    -~SquareArena()
        -closes the ofstring object to outFile

    -SquareArena & operator=(SquareArena &rhs)
        -assignment is not recommended for SquareArena, but it may work


Getter functions
    -std::deque<Food> getAllFood()
        -returns deque of food objects in arena

    -std::vector<Creature> getAllCreatures()
        -returns vector of creature objects in arena

    -std::string getOutFilePath()
        -returns path to outFile

    -float getXSize()
        -returns xSize

    -float getYSize()
        -returns ySize

    -std::string toString()
        -currently unimplemented

    -std::string toDataString()
        -returns data string of the following form:
            creatures in form x,y,energy separated by space,
            then ; then food as x,y,energy separated by space


Boolean functions
    -bool isAnyCreatures()
        -returns true if at least one creature is in the system

    -bool isAnyFood()
        -returns true if at least one food is in the system


Modify creatures and food
    -void addCreature(Creature newCreature)
        -adds the new creature to the end of the creature vector

    -void addFood(Food newFood)
        -adds the new food to the end of the food deque

    -void removeCreatureAtIndex(int loc)
        -removes the creature at a specified index

    -void spawnFood(double energy)
        -spawns food at a random location in the SquareArena
        with the specified energy value


Main function
    -void advance()
        -randomly shuffles the creatures
        -each creature is moved through it's moveToNearestFood function
            -this function will also remove food if it is eaten
        -creatures with high enough energy will reproduce
        -new creatures show up at the end of the list and get a turn this round

*/


#ifndef ARENA_H
#define ARENA_H


#include "Creature.h"
#include <iostream>
#include <deque>
#include <string>
#include <fstream>

class SquareArena {
public:
    //constructors
    SquareArena(float xSize, float ySize, std::string outFilePath);
    SquareArena();
    SquareArena(SquareArena &orig);
    ~SquareArena();
    SquareArena & operator=(SquareArena &rhs);

    // getter functions
    std::deque<Food> getAllFood();
    std::vector<Creature> getAllCreatures();
    std::string getOutFilePath();
    float getXSize();
    float getYSize();
    std::string toString();
    std::string toDataString();

    // boolean functions
    bool isAnyCreatures();
    bool isAnyFood();

    // modify creatures and food
    void addCreature(Creature newCreature);
    void addFood(Food newFood);
    void removeCreatureAtIndex(int loc);
    void spawnFood(double energy);

    // main functions
    void advance();
private:
    void writeHeader();
    void shuffleCreatures();
    Coords randomCoords();
    void writeLine();


    float xMin;
    float xMax;
    float yMin;
    float yMax;
    std::ofstream outFile;
    std::string outFilePath;
    std::deque<Food> allFood;
    std::vector<Creature> allCreatures;
};



#endif //ARENA_H