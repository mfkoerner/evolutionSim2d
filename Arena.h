// Arena.h

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