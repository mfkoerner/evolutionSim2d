// DerivedCreatures1.cpp

#include <string>
#include <iostream>
#include <cstdio>
#include <deque>
#include <cmath>
#include <memory>
#include <vector>
#include "Creature.h"
#include "DerivedCreatures1.h"
#include "helper_functions.h"


using namespace std;


// ******** NearestFoodCreature ******** //

NearestFoodCreature::NearestFoodCreature(Coords position, 
    double energy, double speed, string name) 
    : Creature(position, energy, speed, name) {
    // Everything is already declared in Creature class
}

NearestFoodCreature::NearestFoodCreature() 
    : Creature(Coords(0., 0.), 10., 1., "") {
    // Everything is already declared in Creature class
}

//overrides of virtual functions

unique_ptr<Creature> NearestFoodCreature::clone() {
    return make_unique<NearestFoodCreature>(*this);
}

vector< unique_ptr<Creature> > NearestFoodCreature::makeChildren() {
    setEnergy(getEnergy()/2);
    vector< unique_ptr<Creature> > children;
    children.emplace_back(unique_ptr<Creature>(
        new NearestFoodCreature(getPosition(), getEnergy(), getSpeed(),
            getName())));
    return children;

}

void NearestFoodCreature::advance(deque<Food> &allFood) {
    if (allFood.size() == 0) {
        moveInDirection(Coords(0., 0.));
    } else {
        deque <Food> :: iterator nearest = getNearestFoodIt(allFood);
        double distance=nearest->getPosition().getDistance(this->getPosition());
        // cout << "distance is " << distance << endl; //DEBUG LINE
        double energy_increase = 0;
        string theName = "";
        if (distance <= getSpeed()) {
            energy_increase = nearest->getEnergy();
            theName = nearest->getName();
            allFood.erase(nearest, next(nearest));
            // cout << "ate food " << theName << endl; //DEBUG LINE
        }
        float R = getRandomFloat(0., 1.);
        moveTowardsPointReduced(nearest->getPosition(), R);
        changeEnergy(energy_increase);
    }

}



// ******** MomentumCreature ******** //


MomentumCreature::MomentumCreature(Coords position, double energy,
    double speed, Coords lastVelocity, string name)
    : Creature(position, energy, speed, name) {
        this->lastVelocity = lastVelocity;
}

Coords getLastVelocity() {
    return lastVelocity;
}

unique_ptr<Creature> MomentumCreature::clone() {
    return make_unique<MomentumCreature>(*this);
}

vector< unique_ptr<Creature> > MomentumCreature::makeChildren() {
    setEnergy(getEnergy()/2);
    vector< unique_ptr<Creature> > children;
    children.emplace_back(unique_ptr<Creature> (
        new MomentumCreature(getPosition(), getEnergy(), getSpeed(),
            -1*getLastVelocity(), getName())
    ));
    return children;
}

void MomentumCreature::advance(deque<Food> & allFood) {
    if (allFood.size() == 0) {
        moveInDirection(Coords(0., 0.));
    } else {
        deque <Food> :: iterator nearest = getNearestFoodIt(allFood);
        double distance=nearest->getPosition().getDistance(this->getPosition());
        Coords difference = nearest->getPosition() - this->getPosition();
        // 1.0 means same direction, -1.0 means opposite direction
        double sameDirection = dotProduct(
            difference, this->getLastVelocity()) / ( 
            this->getLastVelocity().getLength() * difference.getLength());
        double energy_increase = 0;
        if (distance <= getSpeed()) {
            energy_increase = nearest->getEnergy();
            allFood.erase(nearest, next(nearest));
            // cout << "ate food " << theName << endl; //DEBUG LINE
        }
        moveByMomentumTowardsPoint(nearest->getPosition());
        changeEnergy(energy_increase);
    }

}

void updateLastVelocity(Coords velocity) {
    lastVelocity = velocity;
}

void moveByMomentumTowardsPoint()







