// Creature.cpp

#include <string>
#include <iostream>
#include <cstdio>
#include <deque>
#include <cmath>
#include "Creature.h"
#include "helper_functions.h"


using namespace std;

const double constTerm = 0.01;
const double speedCoefficient = 0.04;


Creature::Creature(Coords position, double energy, double speed, string name) 
                         : Entity(position, "Creature") {
    this->energy = energy;
    this->speed = speed;
    this->name = name;
    checkEnergy(); checkSpeed();
}

Creature::Creature() : Entity(Coords(0., 0.), "Creature") {
    this->energy = 10.;
    this->speed = 0.;
    this->name = "";
    checkEnergy(); checkSpeed();
}

double Creature::getEnergy() {return energy;}

void Creature::changeEnergy(double difference) {
    energy += difference;
    checkEnergy();
}

void Creature::setEnergy(double energy) {
    this->energy = energy;
    checkEnergy();
}

double Creature::getSpeed() {return speed;}
string Creature::getName() {return name;}

string Creature::toString() {
    string output;
    output = "Creature: " + getName() + "\n energy: " + to_string(getEnergy())
    + "\n speed: " + to_string(getSpeed()) + "\n entity: " + Entity::toString();
    return output;
}

string Creature::toDataString() {
    return getPosition().toString() + "," + to_string(energy);
}


bool Creature::isDead() {
    return energy == 0.;
}
bool Creature::isReadyToReproduce() {
    return energy == 10.;
}

//movement

void Creature::moveInDirection(Coords vector) {
    vector.resizeVector(getSpeed());
    moveAndDecay(vector);

}

void Creature::moveInDirectionReduced(Coords vector, float R) {
    if (R > 1.) {
        R = 1.;
    }
    vector.resizeVector(getSpeed()*R);
    moveAndDecay(vector);

}

void Creature::moveNotAtSpeed(Coords vector) {
    if (vector.getLength() > getSpeed()) {
        moveInDirection(vector);
    }
    moveAndDecay(vector);
}

void Creature::moveTowardsPoint(Coords point) {
    Coords velocity = point - getPosition();
    moveInDirection(velocity);
}

void Creature::moveTowardsPointReduced(Coords point, float R) {
    Coords velocity = point - getPosition();
    moveInDirectionReduced(velocity, R);
}

// void Creature::advance(deque<Food> &allFood) {
//     if (allFood.size() == 0) {
//         moveInDirection(Coords(0., 0.));
//     } else {
//         deque <Food> :: iterator nearest = getNearestFoodIt(allFood);
//         double distance=nearest->getPosition().getDistance(this->getPosition());
//         // cout << "distance is " << distance << endl; //DEBUG LINE
//         double energy_increase = 0;
//         string theName = "";
//         if (distance <= speed) {
//             energy_increase = nearest->getEnergy();
//             theName = nearest->getName();
//             allFood.erase(nearest, next(nearest));
//             // cout << "ate food " << theName << endl; //DEBUG LINE
//         }
//         moveTowardsPoint(nearest->getPosition());
//         changeEnergy(energy_increase);
//     }

// }





//Private functions

void Creature::moveAndDecay(Coords velocity) {
    move(velocity);
    double modifyer;
    // cout << to_string(velocity.getLength()*10000) << endl; //DEBUG LINE
    modifyer = constTerm + speedCoefficient*pow(velocity.getLength(), 2.);
    changeEnergy(-modifyer);
}

deque<Food>::iterator Creature::getNearestFoodIt(deque<Food> &allFood) {
    deque <Food> :: iterator it;
    deque <Food> :: iterator nearest = allFood.begin();
    double nearestDistance = 
          nearest->getPosition().getDistance(this->getPosition());
    double currentDistance;
    for (it = allFood.begin(); it != allFood.end(); it++) {
        currentDistance = it->getPosition().getDistance(this->getPosition());
        if (currentDistance < nearestDistance) {
            nearest = it;
            nearestDistance = currentDistance;
        }
    }
    return nearest;
}

void Creature::checkEnergy() {
    if (energy > 10.) {
        energy = 10.;
    } else if (energy < 0.) {
        energy = 0.;
    }
}

void Creature::checkSpeed() {
    if (speed < 0.)  {
        speed = 0.;
    }
}





//                //
// Food functions //
//                //


Food::Food(Coords location, double energy, string name) 
            : Entity(location, "Food") {
    this->energy = energy;
    this->name = name;
    checkEnergy();
}

Food::Food() : Entity(Coords(0., 0.), "Food") {
    this->energy = 1.;
    this->name = "";
    checkEnergy();
}

//getter and setter

double Food::getEnergy() {return energy;}
string Food::getName() {return name;}

string Food::toString() {
    string output;
    output = "Food: " + getName() + "\n energy: " +
    to_string(energy) + "\n entity: " + Entity::toString();
    return output;
}

string Food::toDataString() {
    return getPosition().toString() + "," + to_string(energy);
}

// private
void Food::checkEnergy(){
    if (energy < 0.) {
        energy = 0.;
    }
}







