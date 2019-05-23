// DerivedCreatures1.h

/*

-- Class: NearestFoodCreature (Inherits from Creature) --
    -Moves towards nearest food on advance
    -Movement is delayed by multiplying by a random number from 0-1
    -For most of documentation, refer to Creature.h
    -Children are identical, but both parent and child get half the energy


    Constructors
        -NearestFoodCreature(Coords position, double energy,
         double speed, std::string name = "")
        -NearestFoodCreature()

    Movement
        -void advance(std::deque<Food> &allFood)
            -moves towards nearest food using moveTowardsPoint
            -if food is withing distance of speed, then
            it will gain the energy of that food and remove it from the food deque


-- Class: MomentumCreature (Inherits from Creature) --
    -These creatures follow a bit more physics and they can't instantly
     turn around
    -Their movement is always of a distance of speed, but they can only have
     a change in velocity of 0.2 max. This limits how far around they can turn.
    -When a baby is born in this class, they move in the opposite direction of
     the parent. This should help with the clustering that kills the
     NearestFoodCreatures

    Constructors
        -MomentumCreature(Coords position, double energy,
        double speed, Coords lastVelocity, std::string name="")
        -MomentumCreature()
            -position (0.,0.), energy 10, speed 1, lastVelocity (0., 1.),
             name=""

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