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

*/



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