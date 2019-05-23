// Creature.h

/*
-- Class: Food (Inherits from Entity) --
    - Food classes have a position and energy, the energy is how much energy
    a creature gains from eating the food

    - As of now, all food classes have an image of "food"


Consructors
    -Food(Coords location, double energy, std::string name = "")
    -Food()


Getter functions
    -double getEnergy()
    -std::string getName()

Setter functions
    -std::string toString()
        -Output format below
            Food: ${name}
            Energy: ${energy}
            Entity: ${string from entity definition}

    -std::string toDataString()
        -outputs a convenient string for plotting purposes
        -liable to change, curretnly of following format
            xPos,yPos,energy
        -floats are to 1e-6 precision because of c++ to_string() function



-- Class: Creature (Inherits from Entity) --
    -Creature classes have position, energy, speed, and name. They move according to
    the logic in advance(std::deque<Food> &allFood).

    -Energy is gained when food is reached, and energy is lost each turn as the
    function E_lost = constant + energy_coefficient * (movement_distance)^2

    -Energy is limited to the range 0-10, Speed does not have a limit.

    -There are some weird features to creatures. They currently grab food automatically if they begin
    their turn within speed of the food, regardless of where they actually moved.

    -Name is currently not implemented, but may be used as a tag for user


Constructors
    -Creature(Coords position, double energy, double speed, std::string name = "")
    -Creature()

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
            Creature: [name]
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
    -Creature makeChild()
        -returns a child creature and subtracts the appropriate birthing energy
        from current creature
        -implementaion liable to change depending on simulation
        -currently divides energy in half and creates identical child in
        current location

Movement

    -void moveInDirection(Coords vector)
        -move distance of speed in direction of given vector

    -void moveInDirectionReduced(Coords vector, float R)
        -move distance of speed * R (max R = 1) in direction of vector
        -if R>1, R is replaced with 1. (functions like moveInDirection)

    -void moveNotAtSpeed(Coords vector)
        -moves by amount of given vector
        -if len(vector) > speed, moves speed in direction of vector

    -void moveTowardsPoint(Coords point)
        -move distance of speed towards given point

    -void moveTowardsPointReduced(Coords point, float R)
        -moves distance of speed * R (max R = 1) towards point
        -if R > 1, replaces R with 1 and acts like moveTowardsPoint

    -void advance(std::deque<Food> &allFood)
        -abstract function to be implemented by derived classes
        -needs to be able to eat food if within range
        -needs to move the creature is some way in order to get food
        -needs to be implemented in a way that costs energy

*/



#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include <iostream>
#include <deque>
#include <string>
#include <memory>

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
    virtual std::unique_ptr<Creature> clone() =0;

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
    virtual std::vector< std::unique_ptr<Creature> > makeChildren() =0;

    //movement
    void moveInDirection(Coords vector);
    void moveInDirectionReduced(Coords vector, float R);
    void moveNotAtSpeed(Coords vector);
    void moveTowardsPoint(Coords point);
    void moveTowardsPointReduced(Coords point, float R);
    virtual void advance(std::deque<Food> &allFood) =0;

protected:
    std::deque<Food>::iterator getNearestFoodIt(std::deque<Food> &allFood);

private:
    void moveAndDecay(Coords velocity);
    void checkEnergy();
    void checkSpeed();
    double energy; //from 0 - 10
    double speed; //positive
    std::string name;


};



#endif //CREATURE_H