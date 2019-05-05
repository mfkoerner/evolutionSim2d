// Entity.cpp

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

Entity::Entity(Coords position, string image) {
    this->position = position;
    this->image = image;
}

Entity::Entity(Coords position) {
    this->position = position;
    this->image = "no_image";
}

Entity::Entity() {
    this->position = Coords();
    this->image = "no_image";
}

void Entity::move(Coords velocity) {
    position.move(velocity);
}

Coords Entity::getPosition() {
    return position;
}

string Entity::getImage() {
    return image;
}

string Entity::toString() {
    string output;
    output = "position: " + position.toString() + " image: " + image;
    return output;
}


void Entity::setImage(string image) {
    this->image = image;
}