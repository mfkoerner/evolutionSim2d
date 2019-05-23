// Arena.cpp


#include <iostream>
#include <deque>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Creature.h"
#include "Arena.h"
#include "helper_functions.h"

using namespace std;

// other useful definitions

string stringOfData(deque<Food> foodList) {
    if (foodList.size() == 0) {
    return "";
}
    string output = foodList.begin()->toDataString();
    deque<Food> :: iterator it;
    for (it = next(foodList.begin()); it != foodList.end(); it++) {
        output += " ";
        output += it->toDataString();
    }
    return output;
}
string stringOfData(vector<Creature> creatureVec) {
    if (creatureVec.size() == 0) {
    return "";
}
    string output = creatureVec.begin()->toDataString();
    vector<Creature> :: iterator it;
    for (it = next(creatureVec.begin()); it != creatureVec.end(); it++) {
        output += " ";
        output += it->toDataString();
    }
    return output;
}


// Constructors
SquareArena::SquareArena(float xSize, float ySize, string outFilePath) {
    this->xMin = -xSize/2;
    this->xMax = xSize/2;
    this->yMin = -ySize/2;
    this->yMax = ySize/2;
    this->outFilePath = outFilePath;
    this->outFile.open(this->outFilePath);
    writeHeader();

}

SquareArena::SquareArena() {
    float xSize = 20;
    float ySize = 20;
    string outFilePath = "out.txt";
    this->xMin = -xSize/2;
    this->xMax = xSize/2;
    this->yMin = -ySize/2;
    this->yMax = ySize/2;
    this->outFilePath = outFilePath;
    this->outFile.open(this->outFilePath);
    writeHeader();
}

SquareArena::SquareArena(SquareArena &orig) {
    this->xMin = -orig.getXSize()/2;
    this->xMax = orig.getXSize()/2;
    this->yMin = -orig.getYSize()/2;
    this->yMax = orig.getYSize()/2;
    this->outFilePath = orig.getOutFilePath();
    this->outFile.open(this->outFilePath);
    this->allFood = orig.getAllFood();
    this->allCreatures = orig.getAllCreatures();
    writeHeader();
}

SquareArena::~SquareArena() {
    this->outFile.close();
}

SquareArena & SquareArena::operator=(SquareArena &rhs) {
    cout << "Using assignment with Arena objects is not recommended\n";
    this->~SquareArena();
    SquareArena(rhs.getXSize(), rhs.getYSize(), rhs.getOutFilePath());
    this->allFood = rhs.getAllFood();
    this->allCreatures = rhs.getAllCreatures();

    return *this;
}

// getter functions
deque<Food> SquareArena::getAllFood() {
    return allFood;
}

vector<Creature> SquareArena::getAllCreatures() {
    return allCreatures;
}


string SquareArena::getOutFilePath() {
    return outFilePath;
}

float SquareArena::getXSize() {
    return xMax - xMin;
}

float SquareArena::getYSize() {
    return yMax - yMin;
}

std::string SquareArena::toString() {
    return "STUB\n";
}

std::string SquareArena::toDataString() {
    // cout << stringOfData(allCreatures) << endl; //DEBUG LINE
    // cout << stringOfData(allFood) << endl; //DEBUG LINE
    return stringOfData(allCreatures) + ";" + stringOfData(allFood);
}

// boolean functions
bool SquareArena::isAnyCreatures() {
    return !(allCreatures.size() == 0);
}

bool SquareArena::isAnyFood() {
    return !(allFood.size() == 0);
}


// modify creatures and food
void SquareArena::addCreature(Creature newCreature) {
    allCreatures.push_back(newCreature);
}
void SquareArena::addFood(Food newFood) {
    allFood.push_back(newFood);
}
void SquareArena::removeCreatureAtIndex(int loc) {
    allCreatures.erase(allCreatures.begin() + loc);
}
void SquareArena::spawnFood(double energy) {
    Food newFood(randomCoords(), energy);
    addFood(newFood);
}






void SquareArena::advance() {
    // cout << "advance" << endl; //DEBUG LINE
    shuffleCreatures();
    // cout << "shuffled" << endl; //DEBUG LINE
    int loc = 0;
    while (loc < allCreatures.size()) {
        // cout << "loc = " << loc << endl; //DEBUG LINE
        // allCreatures[loc] = allCreatures.at(loc);
        if (allCreatures[loc].isReadyToReproduce()) {
            Creature child = allCreatures[loc].makeChild();
            addCreature(child);
        }
        if (allCreatures[loc].isDead()) {
            removeCreatureAtIndex(loc);
        } else {
            allCreatures[loc].advance(allFood);
            loc++;
        }
    }
    // cout << "writing" << endl; //DEBUG LINE
    writeLine();
    // cout << "written" << endl; //DEBUG LINE
}



// Private Functions

void SquareArena::writeHeader() {
    outFile << "creatures in format x,y,energy separated by"
    << " space ; food (same format)\n";
    // outFile << "Cr1XPos,Cr1YPos,Cr1Energy Cr2..." << 
    // " ... ...,Cr(N)Energy;Food1XPos,Food1YPos,Food1Energy ...\n";
}

void SquareArena::shuffleCreatures() {
    random_shuffle(allCreatures.begin(), allCreatures.end());
}

Coords SquareArena::randomCoords() {
    return getRandomCoords(xMin, xMax, yMin, yMax);
}

void SquareArena::writeLine() {
    // cout << "before toDataString()" << endl; //DEBUG LINE
    // cout << toDataString() << endl; //DEBUG LINE
    // cout << "after toDataString()" << endl; //DEBUG LINE
    outFile << toDataString() << endl;
}












