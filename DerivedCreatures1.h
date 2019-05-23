// DerivedCreatures1.h

/*

-- Class: NearestFoodCreature (Inherits from Creature) --
    -Moves towards nearest food on advance

    -Movement is delayed by multiplying by a random number from 0-1

    -For most of documentation, refer to Creature.h


Constructors
    -NearestFoodCreature(Coords position, double energy,
     double speed, std::string name = "")
    -NearestFoodCreature()

Movement
    -void advance(std::deque<Food> &allFood)
        -moves towards nearest food using moveTowardsPoint
        -if food is withing distance of speed, then
        it will gain the energy of that food and remove it from the food deque

*/



#ifndef DERIVED_CREATURES_1_H
#define DERIVED_CREATURES_1_H

#include "Creature.h"
#include <iostream>
#include <deque>
#include <string>
#include <memory>


class NearestFoodCreature : public Creature {
public:
    //constructors
    NearestFoodCreature(Coords position, double energy, double speed,
     std::string name = "");
    NearestFoodCreature();

    //overrides of virtual functions
    std::unique_ptr<Creature> clone();
    std::vector< std::unique_ptr<Creature> > makeChildren();
    void advance(std::deque<Food> &allFood);

};



#endif //DERIVED_CREATURES_1_H