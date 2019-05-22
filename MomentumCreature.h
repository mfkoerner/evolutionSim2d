// MomentumCreature.h

/*

-- Class: MomentumCreature (Inherits from Creature) --
    -MomentumCreature classes have position, energy, speed, and name.
    They move according to the logic in 
    moveToNearestFood(std::deque<Food> &allFood).

    -Energy is gained when food is reached, and energy is lost each turn as the
    function E_lost = constant + energy_coefficient * (movement_distance)^2

    -Energy is limited to the range 0-10, Speed does not have a limit.

    -Momentum creatues are limited to an overall momentum change of 1 unit
    this means that the angle may only change by 1 unit / speed in any turn

    -Name is currently not implemented, but may be used as a tag for user


Constructors
    -MomentumCreature(Coords position, double energy, double speed, std::string name = "")
    -MomentumCreature()

getter and setter
    -double getEnergy()
        -returns double of energy between 0 and 10

    -void changeEnergy(double difference)
        -newEnergy = oldEnergy + difference
        -logic restricts energy from going below 0 or above 10

    -void setEnergy(double energy)
        -sets energy to value
        -if < 0, sets to 0; if > 10, sets to 10

    -double getSpeed()
        -returns speed

    -std::string getName()
        -returns name

    -std::string toString()
        -returns in below format
            MomentumCreature: [name]
            Energy: [energy]
            Speed: [speed]
            Entity: x,y   creature

    -std::string toDataString()
        -returns data in following format
            "(x,y,energy)"

    -bool isDead()
        -returns True if energy == 0

    -bool isReadyToReproduce()
        returns True if energy == 10 (could be later changed)

Reproduction
    -MomentumCreature makeChild()
        -returns a child creature and subtracts the appropriate birthing energy
        from current creature
        -implementaion liable to change depending on simulation
        -currently divides energy in half and creates identical child in
        current location

Movement
    -void moveInDirection(Coords vector)
        -move distance of R*speed in direction of given vector

    -void moveTowardsPoint(Coords point)
        -move distance of R*speed towards given point

    -void moveToNearestFood(std::deque<Food> &allFood)
        -moves towards nearest food using moveTowardsPoint
        -if food is withing distance of speed (regardless of R chosen), then
        it will gain the energy of that food and remove it from the food deque

*/



#ifndef MOMENTUM_CREATURE_H
#define MOMENTUM_CREATURE_H

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


class MomentumCreature : public Entity {
public:
    //constructors
    MomentumCreature(Coords position, double energy, double speed, std::string name = "");
    MomentumCreature();

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
    MomentumCreature makeChild();

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



#endif //MOMENTUM_CREATURE_H