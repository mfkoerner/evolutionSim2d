// Creature.h

#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include <iostream>
#include <deque>
#include <string>

class Food : public Entity {
public:
    Food(Coords location, double energy, std::string name = "");
    Food();
    double getEnergy();
    std::string getName();

    std::string toString();
    std::string toDataString();

private:
    void checkEnergy();
    double energy; // energy >= 0
    std::string name;
};


class Creature : public Entity {
public:
    //constructors
    Creature(Coords position, double energy, double speed, std::string name = "");
    Creature();

    //gettor and settor
    double getEnergy();
    void changeEnergy(double difference);
    void setEnergy(double energy);

    double getSpeed();
    std::string getName();

    std::string toString();
    std::string toDataString();

    bool isDead();
    bool isReadyToReproduce();

    //reproduction
    Creature makeChild();

    //movement
    void moveInDirection(Coords vector);
    void moveTowardsPoint(Coords point);
    void moveToNearestFood(std::deque<Food> &allFood);



private:
    void advance(Coords velocity);
    std::deque<Food>::iterator getNearestFoodIt(std::deque<Food> &allFood);
    void checkEnergy();
    void checkSpeed();
    double energy; //from 0 - 10
    double speed; //positive
    std::string name;


};



#endif //CREATURE_H